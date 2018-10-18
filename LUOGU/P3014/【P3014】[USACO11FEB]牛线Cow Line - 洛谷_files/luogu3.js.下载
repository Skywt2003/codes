/**
 * Created by Administrator on 2015/10/29.
 */

;
(function ($) {
    /*
     * 文本域光标操作（选、添、删、取）
     */
    $.fn.extend({
        /*
         * 获取光标所在位置
         */
        iGetFieldPos: function () {
            var field = this.get(0);
            if (document.selection) {
                //IE
                $(this).focus();
                var sel = document.selection;
                var range = sel.createRange();
                var dupRange = range.duplicate();
                dupRange.moveToElementText(field);
                dupRange.setEndPoint('EndToEnd', range);
                field.selectionStart = dupRange.text.length - range.text.length;
                field.selectionEnd = field.selectionStart + range.text.length;
            }
            return field.selectionStart;
        },
        /*
         * 选中指定位置内字符 || 设置光标位置
         * --- 从start起选中(含第start个)，到第end结束（不含第end个）
         * --- 若不输入end值，即为设置光标的位置（第start字符后）
         */
        iSelectField: function (start, end) {
            var field = this.get(0);
            //end未定义，则为设置光标位置
            if (arguments[1] == undefined) {
                end = start;
            }
            if (document.selection) {
                //IE
                var range = field.createTextRange();
                range.moveEnd('character', -$(this).val().length);
                range.moveEnd('character', end);
                range.moveStart('character', start);
                range.select();
            } else {
                //非IE
                field.setSelectionRange(start, end);
                $(this).focus();
            }
        },
        /*
         * 选中指定字符串
         */
        iSelectStr: function (str) {
            var field = this.get(0);
            var i = $(this).val().indexOf(str);
            i != -1 ? $(this).iSelectField(i, i + str.length) : false;
        },
        /*
         * 在光标之后插入字符串
         */
        iAddField: function (str) {
            var field = this.get(0);
            var v = $(this).val();
            var len = $(this).val().length;
            if (document.selection) {
                //IE
                $(this).focus()
                document.selection.createRange().text = str;
            } else {
                //非IE
                var selPos = field.selectionStart;
                $(this).val($(this).val().slice(0, field.selectionStart) + str + $(this).val().slice(field.selectionStart, len));
                this.iSelectField(selPos + str.length);
            };
        },
        /*
         * 删除光标前面(-)或者后面(+)的n个字符
         */
        iDelField: function (n) {
            var field = this.get(0);
            var pos = $(this).iGetFieldPos();
            var v = $(this).val();
            //大于0则删除后面，小于0则删除前面
            $(this).val(n > 0 ? v.slice(0, pos - n) + v.slice(pos) : v.slice(0, pos) + v.slice(pos - n));
            $(this).iSelectField(pos - (n < 0 ? 0 : n));
        }
    });
})(jQuery);


function show_alert(title, message) {
    $('#lg-alert-title').html(title);
    $('#lg-alert-message').html(message);
    $('#lg-alert').modal('open');
}

function login() {
    var username = $("[name=username]").val();
    var password = $("[name=password]").val();
    var redirect = $("[name=redirect]").val();
    var cookie = $("[name=cookie]:checked").val();
    var two_factor = $("#login-2fa-prompt").find("input[type=text]").val();
    var verify = $("[name=verify]").val();
    if (cookie === undefined) cookie = 0;
    $.post("/login/loginpage", {
        username: username,
        password: password,
        cookie: cookie,
        two_factor: two_factor,
        redirect: redirect,
        verify: verify
    },
    function (data) {
        var res;
        res = eval("(" + data + ")");
        if (res["code"] !== 200) {
            show_alert("好像哪里有点问题", res["message"]);
            $("[name=login]").removeClass("am-disabled");
        } else {
            window.location.href = res["more"]["goto"];
        }

        if(typeof grecaptcha !== "undefined")
            grecaptcha.reset();
    });
}

function pre_login() {
    var username = $("[name=username]").val();
    if (!username) {
        show_alert("提示", "请输入你的用户名");
        return;
    }

    $("[name=login]").addClass("am-disabled");

    if(typeof grecaptcha !== "undefined")
        grecaptcha.execute();
    else
        login();
}

function rebind() {
    $("[name=login]").click(pre_login);
    $("[name=password]").keyup(function (event) {
        if (event.keyCode === 13) {
            pre_login();
        }
    });

    $(document).pjax('[data-pjax] a, a[data-pjax]', '.lg-content', {
        timeout: 6000
    });


    $('#lg-slider').flexslider();
    $(".lg-toolbar[data-am-sticky]").sticky();

    $('select').selected();
    $('[class*=am-checkbox]>input[type=checkbox], [class*=am-radio]>input[type=radio]').uCheck();
    $("[name=verifybox]").click(
        function () {
            $("[name=verifybox]").html(verify);
        }
    );

    $('#lg-offcanvas').offCanvas('close');
    $('.am-dropdown').dropdown('close');
    //$('#topbar-collapse').collapse('close')

    $('pre code').each(function (i, block) {
        //window.console.log($(block));
        hljs.highlightBlock(block);
    });

    var render_math = renderMathInElement;
    if(typeof renderMathInElement !== "function")
        render_math = renderMathInElement.default;
    render_math(document.getElementsByClassName("lg-content")[0], {
        delimiters: [{
                left: "$$",
                right: "$$",
                display: true
            },
            {
                left: "$",
                right: "$",
                display: false
            },
            {
                left: "\\[",
                right: "\\]",
                display: true
            },
            {
                left: "\\(",
                right: "\\)",
                display: false
            }
        ],
        throwOnError: false
    });

    renderCaptcha();
}


function goto_url(url, param) {
    var flag = 0;
    for (var key in param) {
        url = url + ((!flag) ? '?' : '&');
        url = url + key + '=' + encodeURIComponent(param[key]);
        flag = 1;
    }
    //alert(url);
    $.pjax({
        url: url,
        container: '.lg-content',
        timeout: 10000
    });
    //window.location=url;
}

$(document).on('pjax:beforeSend', function (event, xhr, options) {
    refer = window.location.href;
    if (typeof (infotimeout) != "undefined") {
        clearTimeout(infotimeout);
    }

    var csrf_token = $('meta[name=csrf-token]').attr('content');
    if (csrf_token)
        xhr.setRequestHeader('X-CSRF-Token', csrf_token);
});

$(document).on('pjax:send', function () {
    $.AMUI.progress.start();
});
$(document).on('pjax:complete', function () {
    $.AMUI.progress.done();
    getunreadtime = 10;
    rebind();
    var url = window.location.pathname + window.location.search;
    if (typeof _czc !== 'undefined')
        _czc.push(["_trackPageview", url, refer]);
});

function get_unread() {
    if (!document.hasFocus()) return;
    $('.lg-unread').remove();
    $.get("/space/ajax_getchatnum",
        function (data) {
            var arr = eval('(' + data + ')');
            var right = 60;
            var myuid = $('[myuid]').attr('myuid');
            if (arr['more']['messagenum']) {
                $('body').append(
                    '<a data-pjax href="/space/show?uid=' + myuid + '#message" id="unread-message">' +
                    '<div class="lg-unread" style="right: ' + right + 'px">' +
                    '<div class="lg-unread-icon"><i class="am-icon-envelope"></i></div>' +
                    '<div>新私信</div>' +
                    '</div></a>'
                );
                right += 90;
            }
            if (arr['more']['noticenum'])
                $('body').append(
                    '<a data-pjax href="/space/show?uid=' + myuid + '#mynotice" id="unread-notice">' +
                    '<div class="lg-unread" style="right: ' + right + 'px">' +
                    '<div class="lg-unread-icon"><i class="am-icon-paper-plane"></i></div>' +
                    '<div>新通知</div>' +
                    '</div></a>'
                );
            $('.lg-unread').fadeOut(500).fadeIn(500).fadeOut(500).fadeIn(500);
        }
    );
    if (getunreadtime--)
        setTimeout('get_unread()', 600000);
}

$(document).ready(function () {
    if ($('[myuid]') && $('[myuid]').attr('myuid')) {
        setTimeout('get_unread()', 10000);
    }
    if (typeof (hljs) != "undefined") {
        hljs.configure({
            tabReplace: '    '
        });
        $(".lg-nav-btn").poshytip({
            className: 'tip-twitter',
            showTimeout: 1,
            alignTo: 'target',
            alignX: 'right',
            alignY: 'center',
            offsetX: 15
        });
    }

    rebind();
    $(".lg-article-sub").hide();
    initTop = 1;
});










function resize_ide() {
    var left = $('.lg-content').offset().left + $('.lg-content').width();
    var ide_width = $(window).width() - left;
    var ide_height = $(window).height() - 65;
    $('.lg-ide-frame').css('left', left).height(ide_height).width(ide_width);
}

function switch_online_coding(action) {
    if (action) {
        if (online_coding) return;
        $('.lg-content')
            .css('width', ($(window).width() / 2) + 'px')
            .css('display', 'inline-block');
        $('.lg-ide-frame')
            .css('display', 'inline-block')
            .fadeIn(2000);
        resize_ide();
        $('[name=problemright]').hide();
        $('[name=problemleft]').removeClass('am-u-md-8').addClass('am-u-md-12');
        online_coding = 1;
        $('[name=exitide]', window.frames["ide"].document).click(function () {
            alert('sss');
            switch_online_coding(0);
        });
    } else {
        if (!online_coding) return;
        $('.lg-content')
            .css('width', 'auto')
            .css('display', 'block');
        $('.lg-ide-frame')
            .css('display', 'none')
            .fadeOut(2000);
        $('[name=problemright]').show();
        $('[name=problemleft]').removeClass('am-u-md-12').addClass('am-u-md-8');
        online_coding = 0;
    }
}
/*
$(window).resize(function(){
    alert('ssss');
    if(online_coding)
        resize_ide();
});
*/
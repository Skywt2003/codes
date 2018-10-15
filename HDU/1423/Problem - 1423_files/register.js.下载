var Wi = [ 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1 ];    // 加权因子   
var ValideCode = [ 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2 ];            // 身份证验证位值.10代表X   
function IdCardValidate(idCard) { 
	
    idCard = trim(idCard.replace(/ /g, ""));               //去掉字符串头尾空格                     
    if (idCard.length == 15) {   
        return isValidityBrithBy15IdCard(idCard);       //进行15位身份证的验证    
    } else if (idCard.length == 18) {   
        var a_idCard = idCard.split("");                // 得到身份证数组   
        if(isValidityBrithBy18IdCard(idCard)&&isTrueValidateCodeBy18IdCard(a_idCard)){   //进行18位身份证的基本验证和第18位的验证
            return true;   
        }else {   
            return false;   
        }   
    } else {   
        return false;   
    }   
}   
/**  
 * 判断身份证号码为18位时最后的验证位是否正确
 * @param a_idCard 身份证号码数组  
 * @return  
 */  
function isTrueValidateCodeBy18IdCard(a_idCard) {   
    var sum = 0;                             // 声明加权求和变量   
    if (a_idCard[17].toLowerCase() == 'x') {   
        a_idCard[17] = 10;                    // 将最后位为x的验证码替换为10方便后续操作   
    }   
    for ( var i = 0; i < 17; i++) {   
        sum += Wi[i] * a_idCard[i];            // 加权求和   
    }   
    valCodePosition = sum % 11;                // 得到验证码所位置   
    if (a_idCard[17] == ValideCode[valCodePosition]) {   
        return true;   
    } else {   
        return false;   
    }   
}   
/**  
  * 验证18位数身份证号码中的生日是否是有效生日  
  * @param idCard 18位书身份证字符串  
  * @return  
  */  
function isValidityBrithBy18IdCard(idCard18){   
    var year =  idCard18.substring(6,10);   
    var month = idCard18.substring(10,12);   
    var day = idCard18.substring(12,14);   
    var temp_date = new Date(year,parseFloat(month)-1,parseFloat(day));   
    // 这里用getFullYear()获取年份，避免千年虫问题   
    if(temp_date.getFullYear()!=parseFloat(year)   
          ||temp_date.getMonth()!=parseFloat(month)-1   
          ||temp_date.getDate()!=parseFloat(day)){   
            return false;   
    }else{
        return true;   
    }   
}   
  /**  
   * 验证15位数身份证号码中的生日是否是有效生日  
   * @param idCard15 15位书身份证字符串  
   * @return  
   */  
  function isValidityBrithBy15IdCard(idCard15){   
      var year =  idCard15.substring(6,8);   
      var month = idCard15.substring(8,10);   
      var day = idCard15.substring(10,12);   
      var temp_date = new Date(year,parseFloat(month)-1,parseFloat(day));   
      // 对于老身份证中的你年龄则不需考虑千年虫问题而使用getYear()方法   
      if(temp_date.getYear()!=parseFloat(year)   
              ||temp_date.getMonth()!=parseFloat(month)-1   
              ||temp_date.getDate()!=parseFloat(day)){   
                return false;   
        }else{   
            return true;   
        }   
  }   
//去掉字符串头尾空格   
function trim(str) {   
    return str.replace(/(^\s*)|(\s*$)/g, "");   
}


/*function reghint(val)
{
	if (val.length==0)
	{ 
		document.getElementById("hint").innerHTML="";
		return;
	}
	var xmlhttp;
	if(window.XMLHttpRequest)
	{
		xmlhttp = new XMLHttpRequest();
	}else
	{
		xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}

	xmlhttp.onreadystatechange = function(){
		document.getElementById("hint").innerHTML=xmlhttp.responseText;
	}
	xmlhttp.open("GET","/QQ2013/ajax.php?key="+val,true);
	xmlhttp.send();
}*/


function isEmail(){

  	var reg = /^[_.0-9a-z-]+@([0-9a-z][0-9a-z-]+.)+[a-z]{2,3}$/;
  	var val = document.getElementById("email").value;
  	val.toLowerCase();
  	var obj = document.getElementById("checkmail");

  	if(reg.test(val)){
  		obj.innerHTML = "<font color=green>OK</font>";
  		return true;
  	}
  	else if(val.length != 0){
  		obj.innerHTML = "<font color=red>Invalid</font>";
  		return false;
  	}else{
  		obj.innerHTML = "";
  		return false;
  	}
}

function isEmpty(){

	var u_name = document.getElementById("usernamez").value;
	if(u_name.length == 0){
		alert("用户ID不能为空");
		return false; 
	}else if(u_name.length > 20){
		alert("用户ID太长");
		return false; 
	}

	var u_pass = document.getElementById("userpassz").value;
	if(u_pass.length == 0){
		alert("密码不能为空");
		return false; 
	}

	var u_pass2 = document.getElementById("userpass2z").value;
	if(u_pass2 != u_pass){
		alert("两次密码不同");
		return false; 
	}
	
	var n_name = document.getElementById("nicknamez").value;
	if(n_name.length == 0){
		alert("昵称不能为空");
		return false; 
	}else if(n_name.length > 64){
		alert("昵称太长");
		return false ;
	}
	
	var year = document.getElementById("yearz").value;
	var now = new Date();
	cyear = parseInt(year);
	var cur_year = now.getFullYear();
	if(year < 1900 || year > cur_year || cyear != year ){
		alert("无效的出生年月");
		return  false;
	}


	var email = document.getElementById("emailz").value;
	if(email.length > 48){
		alert("邮箱太长");
		return false;
	}

	var school = document.getElementById("schoolz").value;
	if(school.length > 64){
		alert("地址太长");
		return false;
	}

	var motto = document.getElementById("mottoz").value;
	if(motto.length > 64){
		alert("座右铭太长");
		return false;
	}

	return true;
}

function valcheck(){

	if(!isEmpty()){
		return false;
	}
	if(!isEmail()){
		alert("无效的邮箱名");
		return false;
	}
	/*$(document).ready(function(){
  		$("#userpass").val(window.md5($("#userpass").val()));
  		$("#userpass2").val(window.md5($("#userpass2").val()));
	});*/
	
	return true;
}

function valcheck2(){

	var name = document.getElementById("name").value;
	if(name.length == 0){
		alert("姓名不能为空");
		return false; 
	}else if(name.length > 50){
		alert("姓名太长");
		return false ;
	}
	
	var number = document.getElementById("number").value;
	if(number.length == 0){
		alert("学号不能为空");
		return false; 
	}else if(number.length > 50){
		alert("学号太长");
		return false ;
	}
	
	var telephone = document.getElementById("telephone").value;
	if(telephone.length == 0){
		alert("手机号不能为空");
		return false; 
	}else if(telephone.length != 11){
		alert("手机号不符合");
		return false ;
	}
	
	var email = document.getElementById("email").value;
	if(email.length > 48){
		alert("邮箱太长");
		return false;
	}
	if(!isEmail()){
		alert("无效的邮箱名");
		return false;
	}
	
	var idnumber = document.getElementById("idnumber").value;
	
	if(!IdCardValidate(idnumber)){
		alert("无效的身份证号");
		return false;	
	}
	
	return true;
}

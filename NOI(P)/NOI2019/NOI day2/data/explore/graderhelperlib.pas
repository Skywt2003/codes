unit graderhelperlib;

interface

procedure modify(x : longint);
function query(x : longint) : longint;
procedure report(x : longint; y : longint);
function check(x : longint) : longint;

procedure graderMain();

implementation

uses explore;

type Adj = record
	head : array[0..199999] of longint;
	next, eto : array[0..1999999] of longint;
	tot : longint;
end;

const
	TOKEN = 'Correct';
	DEBUG = true;

var
	deg, cur_deg : array[0..199999] of longint;
	m_cnt, q_cnt, c_cnt, m_lim, q_lim, c_lim : longint;
	fmod, col : array[0..199999] of boolean;
	frep : array[0..1999999] of boolean;
	e, f, d : Adj;

procedure append(var e : Adj; a, b : longint);
begin
	inc(e.tot, 1);
	e.next[e.tot] := e.head[a];
	e.eto[e.tot] := b;
	e.head[a] := e.tot;
end;

procedure fail(s : string);
begin
	writeln('FAIL: ', s);
	halt();
end;

procedure modify(x : longint);
var k : longint;
begin
	inc(m_cnt, 1);
	if m_cnt > m_lim then fail('Calls of modify exceeds the limitation.');
	fmod[x] := not fmod[x];
	col[x] := not col[x];
	k := f.head[x];
	while k <> 0 do begin
		col[f.eto[k]] := not col[f.eto[k]];
		k := f.next[k];
	end;
	// write('modify ', x, ' query = '); for k := 0 to 5 - 1 do write(query(k)); writeln();
end;

function query(x : longint) : longint;
var
	c : boolean;
	k : longint;
begin
	inc(q_cnt, 1);
	if q_cnt > q_lim then fail('Calls of query exceeds the limitation.');
	c := col[x];
	k := f.head[x];
	while k <> 0 do begin
		c := c xor fmod[f.eto[k]];
		k := f.next[k];
	end;
	if c then query := 1 else query := 0;
end;

function verify(p, fa : longint) : boolean;
var k : longint;
begin
	k := f.head[p];
	verify := false;
	while k <> 0 do begin
		if (f.eto[k] = fa) and not frep[k] then
			begin verify := true; frep[k] := true; break; end;
		k := f.next[k];
	end;
end;

procedure report(x : longint; y : longint);
begin
	if not verify(x, y) and not verify(y, x) then
		fail('Wrong edge or dumplicate edge.');
	cur_deg[x] := cur_deg[x] - 1;
	cur_deg[y] := cur_deg[y] - 1;
end;


function check(x : longint) : longint;
begin
	inc(c_cnt, 1);
	if c_cnt > c_lim then fail('Calls of check exceeds the limitation.');
	if cur_deg[x] = 0 then check := 1 else check := 0;
end;

procedure graderMain();
var 
	N, M, i, a, b, cur_max, p, k, timer, l, r, s : longint;
	q, dfn : array[0..199999] of longint;
begin
	e.tot := 1;
	read(m_lim, q_lim, c_lim);

	read(N, M);

	for i := 0 to M - 1 do begin
		read(a, b);
		if not ((0 <= a) and (a < N) and (0 <= b) and (b < N) and (a <> b)) then
			fail('Invalid input.');
		inc(deg[a], 1);
		inc(deg[b], 1);
		append(e, a, b);
		append(e, b, a);
	end;
	for i := 0 to N - 1 do begin
		cur_deg[i] := deg[i];
		append(d, deg[i], i);
	end;
	cur_max := N - 1;
	timer := 0;
	while cur_max > 0 do begin
		p := -1;
		k := d.head[cur_max];
		while k <> 0 do begin
			d.head[cur_max] := k;
			if cur_deg[d.eto[k]] = cur_max then begin
				p := d.eto[k];
				break;
			end;
			k := d.next[k];
		end;
		if p = -1 then begin cur_max := cur_max - 1; continue; end;
		l := 0; r := 0;
		q[r] := p;
		timer := timer + 1;
		dfn[p] := timer;
		r := r + 1;
		while l <> r do begin
			p := q[l];
			l := l + 1;

			k := e.head[p];
			while k <> 0 do begin
				s := e.eto[k];
				if (s <> -1) and (dfn[s] <> timer) then begin
					q[r] := s;
					r := r + 1;
					dfn[s] := timer;
					e.eto[k] := -1;
					e.eto[k xor 1] := -1;
					cur_deg[p] := cur_deg[p] - 1;
					cur_deg[s] := cur_deg[s] - 1;
					append(f, s, p);
				end;
				k := e.next[k];
			end;

			if cur_deg[p] <> 0 then append(d, cur_deg[p], p);
		end;
	end;

	for i := 0 to N - 1 do cur_deg[i] := deg[i];

	_explore(N, M);

	for i := 0 to N - 1 do if cur_deg[i] <> 0 then fail('Not all edges are reported.');
	writeln(TOKEN);
	if DEBUG then writeln('cnt = ', m_cnt, '/', m_lim, ' ', q_cnt, '/', q_lim, ' ', c_cnt, '/', c_lim);
end;

end.
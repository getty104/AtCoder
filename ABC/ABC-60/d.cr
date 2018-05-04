macro max(a, b)
	{{a}} > {{b}} ? {{a}} : {{b}}
end

macro min(a, b)
	{{a}} < {{b}} ? {{a}} : {{b}}
end

macro swap(a, b)
	{{a}}, {{b}} = {{b}}, {{a}}
end

macro rep(num, &block)
	{{num}}.times {{block}}
end

macro repl(st, en, &block)
	{{st}}.upto {{en}} - 1 {{block}}
end

macro array(size, init = 1)
	Array(typeof({{init}})).new({{size}}){ {{init}} }
end

macro darray(size1, size2, init = 1)
	Array(typeof({{init}}).new({{size1}}){ Array(typeof({{init}}).new({{size2}}){ {{init}} } }
end

macro gi
	gets.not_nil!.split.map do |obj|
		obj = obj.to_u64
	end
end

macro gs
	gets.not_nil!.chomp
end

macro gc
	gets.chomp.split('')
end

macro gif
	gets.to_i
end

macro putall(obj)
	{{obj}}.each do |o|
		puts o
	end
end

macro list(t = Int64)
	[] of {{t}}
end




@@n,@@w = gi
@@wv = list 100000
rep @@n do
	@@wv << gi
end
@@dp = darray @@w+1,2,0
@@wv.sort!

def f jd, data,weight,i
	if @@dp[weight][1] == 1
		if @@dp[weight][0] < data
			@@dp[weight][0] = data
		end
		return @@dp[weight][0] 
	end
	if weight == @@w || i == @@n
		return data 
	end
	if jd == 0
		d = max f(1,data,weight,i+1), f(0,data,weight,i+1)
		if @@dp[weight][0] < d
			@@dp[weight][0] = d
			@@dp[weight][1] = 1
		end
		return d
	else
		ww = weight+@@wv[i][0]
		return data if ww > @@w
		d = max f(1,data+@@wv[i][1],ww,i+1),f(0,data+@@wv[i][1],ww,i+1)
		if @@dp[ww][0] < d
			@@dp[ww][0] = d
			@@dp[ww][1] = 1
		end
		return d
	end 
end

puts max f(1,0,0,0),f(0,0,0,0)

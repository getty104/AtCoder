require 'prime'
include Math
def max(a,b);              a > b ? a : b                              end
def min(a,b);              a < b ?  a : b                             end
def swap(a,b);             a, b = b, a                                end
def gif;                   gets.to_i                                  end
def gff;                   gets.to_f                                  end
def gsf;                   gets.chomp                                 end
def gi;                    gets.split.map(&:to_i)                     end
def gf;                    gets.split.map(&:to_f)                     end
def gs;                    gets.chomp.split.map(&:to_s)               end
def gc;                    gets.chomp.split('')                       end
def pr(num);               num.prime_division                         end
def digit(num);            num.to_s.length                            end
def array(s,ini=nil);      Array.new(s){ini}                          end
def darray(s1,s2,ini=nil); Array.new(s1){Array.new(s2){ini}}          end
def rep(num);              num.times{|i|yield(i)}                     end
def repl(st,en,n=1);       st.step(en,n){|i|yield(i)}                 end



$n,$w = gi
$wv = []
rep $n do
	$wv << gi
end
$dp = darray $w+1,2,0
$wv.sort!

def f jd, data,weight,i
	if $dp[weight][1] == 1
		if $dp[weight][0] < data
			$dp[weight][0] = data
		end
		return $dp[weight][0] 
	end
	if weight == $w || i == $n
		return data 
	end
	if jd == 0
		d = max f(1,data,weight,i+1), f(0,data,weight,i+1)
		if $dp[weight][0] < d
			$dp[weight][0] = d
			$dp[weight][1] = 1
		end
		return d
	else
		ww = weight+$wv[i][0]
		return data if ww > $w
		d = max f(1,data+$wv[i][1],ww,i+1),f(0,data+$wv[i][1],ww,i+1)
		if $dp[ww][0] < d
			$dp[ww][0] = d
			$dp[ww][1] = 1
		end
		return d
	end 
end

puts max f(1,0,0,0),f(0,0,0,0)

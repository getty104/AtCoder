require 'prime'
include Math
def max(a,b);                    a > b ? a : b                            end
def min(a,b);                    a < b ?  a : b                           end
def swap(a,b);                   a, b = b, a                              end
def gif;                         gets.to_i                                end
def gsf;                         gets.chomp                               end
def gi;                          gets.split.map(&:to_i)                   end
def gs;                          gets.chomp.split.map(&:to_s)             end
def gc;                          gets.chomp.split('')                     end
def pr(num);                     num.prime_division                       end
def putall(obj);                 obj.each{|o| puts(o)}                    end
def array(size,init=nil);        Array.new(size){init}                    end
def darray(size1,size2,init=nil);Array.new(size1){Array.new(size2){init}} end
def rep(num);                    num.times {|i|yield(i)}                  end
def repl(st,en);                 st.upto(en) {|i|yield(i)}                end


n,m = gi
x = gi
y = gi
hx = []
hy = []
rep n-1 do |i|
	hx << x[i+1]-x[i]
end
rep m-1 do |i|
	hy << y[i+1]-y[i]
end
s = 0
rep n-1 do |i|
	rep m-1 do |j|
		s+= hx[i]*hy[j]*(n-1-i)*(m-1-j) % ( (10 ** 9)+7 )
	end
end

puts  s
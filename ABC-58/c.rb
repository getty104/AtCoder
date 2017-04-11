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


n = gif
s = []
rep n do
s << gc.sort	
end
sum = []
repl "a", "z" do |al|
	num = Float::INFINITY
	rep n do |i|
		dd = s[i].count al
		num = dd if dd < num
	end

	sum << al * num if num > 0
end

puts sum.join


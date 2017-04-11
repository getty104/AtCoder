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
def rep(num);              num.times {|i|yield(i)}                    end
def repl(st,en,n=1);       n*= -1 if st>en;st.step(en,n){|i|yield(i)} end



s = gc
data = []
rep s.size do |i|
	data.unshift s[s.size-1-i]
	case data.join
	when 'dream'
		data = []
	when 'dreamer'
		data = []
	when 'erase'
		data = []
	when 'eraser'
		data = []
	end
	break if data.size > 7
end

puts data.empty? ? 'YES' : 'NO'



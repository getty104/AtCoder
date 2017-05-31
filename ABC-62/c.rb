require 'prime'
require 'set'
require 'tsort'
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

w , h = gi
a1 = h / 3
a2 = h / 3
a2 += 1 if h % 3 != 0
ans = a2*w-a1*w

a1 = w / 3
a2 = w / 3
a2 += 1 if w % 3 != 0
d = a2*h-a1*h
ans = d if ans > d

rep h-1 do |i|
a = (i+1)*w
b = (h-i-1)*(w/2)
c = (h-i-1)*(w/2+w%2)
ma = max max(a,b), max(a,c)
mi = min min(a,b), min(a,c)
d = ma - mi

ans = d if ans > d
end

rep w-1 do |i|
a = (i+1)*h
b = (w-i-1)*(h/2)
c = (w-i-1)*(h/2+h%2)
ma = max max(a,b), max(a,c)
mi = min min(a,b), min(a,c)
d = ma - mi

ans = d if ans > d
end

puts ans
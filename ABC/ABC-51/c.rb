require 'prime'
require 'set'
require 'tsort'
include Math
ALP = ('a'..'z').to_a
INF = 0xffffffffffffffff
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
def pr?(num);              Prime.prime?(num)                          end
def digit(num);            num.to_s.length                            end
def array(s,ini=nil);      Array.new(s){ini}                          end
def darray(s1,s2,ini=nil); Array.new(s1){Array.new(s2){ini}}          end
def rep(num);              num.times{|i|yield(i)}                     end
def repl(st,en,n=1);       st.step(en,n){|i|yield(i)}                 end
sx,sy,tx,ty = gi
stx1 = tx-sx
stx2 = tx-sx+1
sty1 = ty-sy
sty2 = ty-sy+1
str = []
rep stx1 do |i|
str << 'R'
end

rep sty1 do |i|
str << 'U'
end

rep stx1 do |i|
str << 'L'
end

rep sty1 do |i|
str << 'D'
end

str << 'D'

rep stx2 do |i|
str << 'R'
end

rep sty2 do |i|
str << 'U'
end

str << 'L'
str << 'U'

rep stx2 do |i|
str << 'L'
end

rep sty2 do |i|
str << 'D'
end

str << 'R'

puts str.join

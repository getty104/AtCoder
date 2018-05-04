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


x,y = 0,0
set = gc
t = gif
buff = 0
set.each do |s|
  case s
  when 'L'
    x-=1
  when 'R'
    x+=1
  when 'U'
    y+=1
  when 'D'
    y-=1
  when '?'
    buff+=1
  end
end
if t == 1
  rep buff do
    if x >= 0
      x += 1
    else
      x -= 1
    end
  end
else
  rep buff do
    if x > 0
      x -= 1
    elsif x < 0
      x += 1
    elsif y > 0
      y -= 1
    elsif y < 0
      y += 1
    else
      x += 1
    end
  end
end

puts x.abs+y.abs

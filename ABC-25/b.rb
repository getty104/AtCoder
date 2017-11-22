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


e,w = 'East','West'

n,a,b = gi
point = 0
rep n do |i|
  h,l = gs
  op1 = case h
  when e
    '+'
  when w
    '-'
  end
  l = l.to_i
  op2 = case
  when l < a
    a.to_s
  when l >= a && l <= b
    l.to_s
  when l > b
    b.to_s
  end
  eval "point #{op1}= #{op2}"
end

if point > 0
  puts "East #{point.abs}"
elsif point < 0
  puts "West #{point.abs}"
else
  puts point
end

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

n = gif
a = gi
mx = a.max
mn = a.min
ans = []
if mx.abs > mn.abs
  idx = a.index mx
  rep n do |i|
    a[i] += mx
    ans << "#{idx+1} #{i+1}"
  end
  rep n-1 do |i|
    a[i+1] += a[i]
    ans << "#{i+1} #{i+2}"
  end
else
  idx = a.index mn
  rep n do |i|
    a[i] += mn
    ans << "#{idx+1} #{i+1}"
  end
  repl n-2,0,-1 do |i|
    a[i] += a[i+1]
    ans << "#{i+2} #{i+1}"
  end
end

puts ans.size
puts ans

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


def combi(n,k)
  k = n-k if 2*k > n
  return 1 if k == 0
  return ((n-k+1)..n).reduce(&:*)/((1..k).reduce(&:*))
end

n = gif
a = gi
num = (array n+1).map{[]}

repl 1,n+1 do |i|
  num[a[i-1]] << i
end
ans = []

repl 1, n+1 do |i|
  if num[i].size > 1
    l = num[i].first
    r = num[i].last
  else
    l = num[i][0]
    r = num[i][0]
  end
 p  ans << ((combi (n+1+l),i)-(combi (l-1+n-r),i-1)) % (10**9+7)
end
puts ans

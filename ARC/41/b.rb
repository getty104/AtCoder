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
n,m=gi
a = []
b = darray n,m,0
rep n do
  a << gc.map(&:to_i)
end

rep n do |i|
  rep m do |j|
    if (i + 2 < n) && (j - 1 >= 0 ) && (i+1 < n) && (j+1 < m) && (a[i][j] - a[i+2][j] >= 0)  && (a[i][j] - a[i+1][j-1] >= 0) && (a[i][j] - a[i+1][j+1] >= 0)
      b[i+1][j] += a[i][j]
      a[i+1][j] -= a[i][j]
      a[i+1][j]
    end
  end
  end
end

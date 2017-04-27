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
def rep(num);              num.times{|i|yield(i)}                     end
def repl(st,en,n=1);       st.step(en,n){|i|yield(i)}                 end

def f(sum,a,count)
  repl 1,a.size-1 do |i|
    sum << a[i]+sum[i-1]
    if sum[i-1] > 0
      if sum[i] >= 0
        count += sum[i]+1
        sum[i] = -1
      end
    elsif sum[i-1] < 0
      if sum[i] <= 0
        count += 1-sum[i]
        sum[i] = 1
      end
    end
  end
  return count
end

n = gif
a = gi
sum2 = []
sum3 = []
ans2 = nil
ans3 = nil
if a[0]>0
  sum2 << a[0]
  ans2 = f sum2,a,0
  sum3 << -1
  ans3 = f sum3,a,(1+a[0]).abs
elsif a[0]<0
  sum2 << 1
  ans2 = f sum2,a,1-a[0]
  sum3 << a[0]
  ans3 = f sum3,a,0
else
  sum2 << 1
  ans2 = f sum2,a,1
  sum3 << -1
  ans3 = f sum3,a,1
end

puts min ans2,ans3

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


h,w = gi
m = []
rep h do
  m << gc
end
s = '#'
ans = darray h,w, 0
rep h do |i|
  rep w do |j|
    if m[i][j] == s
      ans[i][j] = s
      next
    end

    des = [1,2,3,4,5,6,7,8]

    if i == 0
      des.delete 1
      des.delete 2
      des.delete 3
    end

    if i == h-1
      des.delete 5
      des.delete 6
      des.delete 7
    end

    if j == 0
      des.delete 1
      des.delete 7
      des.delete 8
    end

    if j == w-1
      des.delete 3
      des.delete 4
      des.delete 5
    end

    des.each do |k|
      case k
      when 1
    ans[i][j] += 1 if m[i-1][j-1] == s
      when 2
    ans[i][j] += 1 if m[i-1][j] == s
      when 3
    ans[i][j] += 1 if m[i-1][j+1] == s
      when 4
    ans[i][j] += 1 if m[i][j+1] == s
      when 5
    ans[i][j] += 1 if m[i+1][j+1] == s
      when 6
    ans[i][j] += 1 if m[i+1][j] == s
      when 7
    ans[i][j] += 1 if m[i+1][j-1] == s
      when 8
    ans[i][j] += 1 if m[i][j-1] == s
      end
    end
  end
end
ans.each do |a|
 puts a.join
end

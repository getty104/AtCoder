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

h,w=gi
sx,sy=gi
a=[]
rep h do
  a << gi
end
sx-=1
sy-=1
dx = [0,1,0,-1]
dy = [1,0,-1,0]
mp = darray h,w,'.'
mp[sx][sy] = 'W'
loop() do
  mx = sx
  my = sy
  rep 4 do |i|
    tx = sx+dx[i]
    ty = sy+dy[i]

    if tx >= 0 && tx < h && ty >= 0 && ty < w
      if a[mx][my] > a[tx][ty]
        mx = tx
        my = ty
      end
    end
  end
  break if mx == sx && my == sy
  mp[mx][my] = 'W'
  sx = mx
  sy = my
end

puts mp.map{|t|t.join}

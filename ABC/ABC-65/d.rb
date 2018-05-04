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
class UnionFindTree

  class ParArray < Hash
    def [] key
      self[key] = key if super(key).nil?
      super(key)
    end
  end

  class SizeArray < Hash
    def [] key
      self[key] = 1 if super(key).nil?
      super(key)
    end
  end

  def initialize()
    @par = ParArray.new
    @size = SizeArray.new
  end

  private

  def find(x)
    return x if x == @par[x]
    return @par[x] = find(@par[x])
  end

  public

  def unite(x, y)
    x = find(x)
    y = find(y)

    return nil if x == y
    x, y = y, x if @size[x] < @size[y]

    @par[y] = x
    @size[x] += @size[y]
  end

  def same?(x, y)
    return find(x) == find(y)
  end

  def size(x)
    return @size[find(x)]
  end

end


n = gif
x = []
y = []
rep n do |i|
  xx,yy = gi
  x << [xx,i]
  y << [yy,i]
end
p x.sort!
p y.sort!
cost = []
tx0 = x[0][0]
tx1 = x[0][1]
ty0 = y[0][0]
ty1 = y[0][1]
repl 1, n-1 do |i|
  nx0 = x[i][0]
  nx1 = x[i][1]
  ny0 = y[i][0]
  ny1 = y[i][1]
  cost << [nx0-tx0,[nx1,tx1]]
  cost << [ny0-ty0,[ny1,ty1]]
  tx0 = nx0
  tx1 = nx1
  ty0 = ny0
  ty1 = ny1
end
p cost.sort!
un = UnionFindTree.new
ans = 0

cost.each do |c|
  break if un.size(0) >= n
  unless un.same? c[1][0],c[1][1]
    un.unite c[1][0],c[1][1]
    ans += c[0]
  end
end
puts ans

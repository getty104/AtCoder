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



class PriorityQueue
  def initialize
    @size = 0
    @heap = []
  end
  private
  def maxHeapify x
    l = 2*x
    r = 2*x+1
    if l <= @size && @heap[l][0] > @heap[x][0]
      largest = l
    else
      largest = x
    end
    if r <= @size && @heap[r][0] > @heap[largest][0]
      largest = r
    end
    if largest != x
      @heap[x], @heap[largest] = @heap[largest], @heap[x]
      maxHeapify(largest)
    end
  end

  public

  def pop
    data = @heap[1][1]
    @heap[1] = @heap[@size]
    @size -= 1
    maxHeapify(1)
    data
  end

  def push key,data
    @size += 1
    @heap[@size] = [key,data]
    i = @size
    while i > 1 && @heap[i/2][0] < @heap[i][0]
      @heap[i], @heap[i/2] = @heap[i/2], @heap[i]
      i /= 2
    end
  end

  def << key
    push key,key
  end

  def empty?
    @heap.empty?
  end

  def size
    @heap.size
  end
end


n = gif
lq = PriorityQueue.new
rq = PriorityQueue.new
a = gi
ls = []
rs = []
sum = 0
rep n do |i|
  lq << -a[i]
  sum += a[i]
end
ls << sum
sum = 0
repl 2*n,3*n-1 do |i|
  rq << a[i]
  sum += a[i]
end

rs << sum

repl n,2*n-1 do |i|
  lq << -a[i]
  tmp = -lq.pop
  ls << ls[-1] + a[i] - tmp
end

repl 2*n-1,n,-1 do |i|
  rq << a[i]
  tmp = rq.pop
  rs << rs[-1] + a[i] - tmp
end

max = -Float::INFINITY
rep n do |i|
  tmp = ls[i]-rs[n-i]
  max = tmp if max < tmp
end

puts max

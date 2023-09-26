def is_prime(num)
    return false if num < 2
    return true if num == 2 || num == 3
    return false if num % 2 == 0 || num % 3 == 0
  
    i = 5
    while i * i <= num
      return false if num % i == 0 || num % (i + 2) == 0
      i += 6
    end
  
    true
  end
  
  def get_input
    k = 0
    loop do
      print "Type a number: "
      k = gets.chomp.to_i
      break if k >= 2
    end
    k
  end
  
  def print_primes(n)
    (2..n).each { |i| puts i if is_prime(i) }
  end
  
  k = get_input
  print_primes(k)
  
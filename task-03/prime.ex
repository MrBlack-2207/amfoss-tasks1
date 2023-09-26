defmodule Prime do
  def is_prime(num) do
    if num < 2 do
      false
    else
      do_is_prime(num, 2)
    end
  end

  defp do_is_prime(num, i) when i*i > num do
    true
  end
  defp do_is_prime(num, i) when rem(num, i) == 0 do
    false
  end
  defp do_is_prime(num, i) do
    do_is_prime(num, i + 1)
  end

  defp get_input do
    IO.puts "Type a number: "
    input = String.trim(IO.gets(""))
    case String.to_integer(input) do
      n when n >= 2 -> n
      _ -> get_input()
    end
  end

  defp print_primes(2) do
    IO.puts 2
  end
  defp print_primes(n) do
    print_primes(n-1)
    if is_prime(n) do
      IO.puts n
    end
  end

  def main do
    k = get_input()
    print_primes(k)
  end
end

Prime.main()




def is_prime(num):
    if num < 2:
        return False
    if num == 2 or num == 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False

    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6

    return True


def get_input():
    k = 0
    while k < 2:
        k = int(input("Type a number: "))
    return k


def print_primes(n):
    for i in range(2, n + 1):
        if is_prime(i):
            print(i)


k = get_input()
print_primes(k)

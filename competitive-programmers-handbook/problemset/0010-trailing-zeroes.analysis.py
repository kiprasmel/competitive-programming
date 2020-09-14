from math import factorial, floor, log
import math

def get_trailing_zeroes(str):
    sum = 0
    
    for i in range(len(str) - 1, 0, -1):
        c = str[i]
        if c != '0':
            break
        else:
            sum = sum + 1

    return sum

def how_many_trailing_zeroes_in_factorial_of(n):
    trailing_zeroes = 0
    pow_of_5 = 1

    while (pow_of_5 <= n):
        pow_of_5 *= 5
        trailing_zeroes += math.floor(n / pow_of_5)

    return trailing_zeroes


last_count = 0
curr_sum = 0

bad_attempts = 0

for i in range (1, 10001):
    count = get_trailing_zeroes(str(factorial(i)))

    if count == last_count:
        curr_sum = curr_sum + 1
    else:
        print ("")

        if count - last_count > 1:
            print ("diff = ", count - last_count, "\n")

        last_count = count
        curr_sum = 1

    # trailing_zeroes = O1_how_many_trailing_zeroes_in_factorial_of(i)
    ## trailing_zeroes = v2(i)
    trailing_zeroes = how_many_trailing_zeroes_in_factorial_of(i)

    if trailing_zeroes != count:
        bad_attempts = bad_attempts + 1

    print(i, "\t", count, curr_sum, trailing_zeroes, bad_attempts)

"""

analysis result:

I realized that once every 5 numbers, starting at 0, the amount of trailing zeroes from a factorial increases by 1,
and once every 25 numbers, the amount increases by (1 + 1 extra) = 2,
and further for each power of 5 (5 (+1), 25 (+2), 125 (+3), 625 (+4) etc.)

in the start, for the first two, it looked like this:
((n / 5) + (n / 25))

Finally, the general formula to get the amount of trailing zeroes a factorial(n) will have is:

~~floor(log5(n)) => floor(log(n) / log(5))~~

def how_many_trailing_zeroes_in_factorial_of(n):
    trailing_zeroes = 0
    pow_of_5 = 1

    while (pow_of_5 <= n):
        pow_of_5 *= 5
        trailing_zeroes += math.floor(n / pow_of_5)

    return trailing_zeroes

---

below is stuff that didn't work. no thanks.

also note:

pow_of_5_occurance_count = log(n) / log(5)

if (625 > n >= 125)
pow_of_5_occurance_count = 3

and trailing_zeroes = ((5 ** 2) + (5 ** 1) + (5 ** 0))

geometric progression to do this in O(1)?

((bk - a) / (k - 1))

k = 5
a = 1
b = 25

trailing_zeroes = ((b  * k - a) / (k - 1))
trailing_zeroes = ((25 * 5 - 1) / (5 - 1))

~~it works!~~
nope

def O1_how_many_trailing_zeroes_in_factorial_of(n):
    pow_of_5_occurance_count = math.log(n) / math.log(5)

    k = 5
    a = 1
    b = 5 ** (pow_of_5_occurance_count - 1)

    trailing_zeroes = ((b * k - a) / (k - 1))

    return trailing_zeroes

---

def O1_how_many_trailing_zeroes_in_factorial_of(n):
    pow_of_5_occurance_count = math.log(n) / math.log(5)

    k = n < 25 ? 5 : ((n / 5 ** (pow_of_5_occurance_count - 1)) / (n / 5 ** pow_of_5_occurance_count))
    a = math.floor(n / (5 ** pow_of_5_occurance_count))
    b = math.floor(n / 5)

    trailing_zeroes = ((b * k - a) / (k - 1))

    return trailing_zeroes

--- 

def v2(n):
    pow_of_5_occurance_count = math.log(n) / math.log(5)

    a = math.floor(n / (5 ** pow_of_5_occurance_count))
    aa = math.floor(n / (5 ** (pow_of_5_occurance_count - 1)))
    k = math.floor(aa / a)
    b = math.floor(n / 5)

    trailing_zeroes = ((b * k - a) / (k - 1))

    return trailing_zeroes

---

"""


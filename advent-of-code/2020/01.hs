twoSum2020 :: [Int] -> Int
twoSum2020 xs = [a * b | a <- xs, b <- xs, a + b == 2020] !! 0

main :: IO ()
main = interact $ show . twoSum2020 . map read . words


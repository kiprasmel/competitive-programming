threeSum2020 :: [Int] -> Int
threeSum2020 xs = [a * b * c | a <- xs, b <- xs, c <- xs, a + b + c == 2020] !! 0

main :: IO ()
main = interact $ show . threeSum2020 . map read . words


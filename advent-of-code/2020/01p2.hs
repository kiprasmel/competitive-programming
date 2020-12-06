threeSum2020 :: [Int] -> Int
threeSum2020 xs = head $ [a * b * c | a <- xs, b <- xs, c <- xs, a + b + c == 2020]

main :: IO ()
main = interact $ show . threeSum2020 . map read . words

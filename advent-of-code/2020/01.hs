twoSum2020 :: [Int] -> Int
twoSum2020 xs = head $ [a * b | a <- xs, b <- xs, a + b == 2020]

main :: IO ()
main = interact $ show . twoSum2020 . map read . words

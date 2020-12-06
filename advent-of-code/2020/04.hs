import Data.List.Split (splitOn)

isValid :: [String] -> Int
isValid xs = if valid then 1 else 0
  where
    valid               = len == 8 || (len == 7 && not hasOptional)
    len                 = length xs
    hasOptional         = "cid" `elem` keys
    keys                = map ((!! 0) . splitOn ":") xs

main :: IO ()
main = interact $ show . sum . map (isValid . words) . splitOn "\n\n"

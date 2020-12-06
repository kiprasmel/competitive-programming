import Data.List       (sort, nub)
import Data.List.Split (splitOn)

countUniqueAnswersInGroup :: [Char] -> Int
countUniqueAnswersInGroup = length . nub . sort . concat . lines

main :: IO ()
main = interact $ show . sum . map countUniqueAnswersInGroup . splitOn "\n\n"

import Data.List       (sort)
import Data.List.Split (splitOn)

countCommonAnswersInGroup :: [Char] -> Int
countCommonAnswersInGroup xs = length commonAnswers
  where
    commonAnswers                      = filter doesEveryoneElseHaveThisAnswer leastAmountOfAnswers
    doesEveryoneElseHaveThisAnswer ans = all (\answers -> ans `elem` answers) sortedPersonsAnswers
    leastAmountOfAnswers               = head sortedPersonsAnswers
    sortedPersonsAnswers               = (sort . map sort . lines) xs

main :: IO ()
main = interact $ show . sum . map countCommonAnswersInGroup . splitOn "\n\n"

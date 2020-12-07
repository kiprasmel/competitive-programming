import Data.List.Split (divvy   )
import Data.Maybe      (mapMaybe)

type Key       = String
type From      = Key
type To        = [Key]
type FromTo    = (From, To)
type FromToMap = [FromTo]

parseBagFromLine :: [String] -> Maybe FromTo
parseBagFromLine xs
  | cannotGoAnywhere = Nothing
  | otherwise        = Just (from, to)
  where
    from                 = takeBagAsKey xs
    to
      | cannotGoAnywhere = []
      | otherwise        = map (takeBagAsKey . drop 1) $ divvy 4 4 restXs
    takeBagAsKey         = concat . take 2
    cannotGoAnywhere     = restXs !! 0 == "no" && restXs !! 1 == "other"
    restXs               = drop 4 xs

canReach :: FromToMap -> To -> Bool
canReach xs to
  | "shinygold" `elem` to = True
  | otherwise             = furtherYesNo
  where
    furtherYesNo = any (canReach xs . snd) newFromTos
    newFromTos   = filter (\ft -> (fst ft) `elem` to) xs

countColors :: FromToMap -> Int
countColors xs = length $ filter ((== True) . canReach xs . snd) xs

main :: IO ()
main = interact $ show . countColors . mapMaybe (parseBagFromLine . words) . lines

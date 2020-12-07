import Data.List.Split (divvy)

type Key              = String
type HowMany          = Int
type Bag              = (Key, HowMany)
type BagToBagsPair    = (Key, [Bag])
type FromBagToBagsMap = [BagToBagsPair]

parseBagToBagsPairFromLine :: [String] -> BagToBagsPair
parseBagToBagsPairFromLine xs = (fromBag, toBags)
  where
    fromBag              = parseKey xs
    toBags
      | cannotGoAnywhere = []
      | otherwise        = map parseBag unparsedBagGroups
    parseKey             = concat . take 2
    parseBag             = \bag -> (parseKey $ drop 1 bag, read $ head bag)
    unparsedBagGroups    = divvy 4 4 restXs
    cannotGoAnywhere     = restXs !! 0 == "no" && restXs !! 1 == "other"
    restXs               = drop 4 xs

canReachHowMany :: FromBagToBagsMap -> Bag -> HowMany
canReachHowMany xs bag = howManyOfMe + furtherSum
  where
    from             = fst bag
    howManyOfMe      = snd bag
    furtherSum       = sum $ map ((* howManyOfMe) . (canReachHowMany xs)) newBags
    newBags          = snd newBagToBagsPair
    newBagToBagsPair = head $ filter ((== from) . fst) xs

countReachableBags :: FromBagToBagsMap -> HowMany
countReachableBags xs = canReachHowMany xs ("shinygold", 1) - 1

main :: IO ()
main = interact $ show . countReachableBags . map (parseBagToBagsPairFromLine . words) . lines

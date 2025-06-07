{-# LANGUAGE CPP #-}

-- Main Program

main :: IO ()
main = putStrLn $ "\n\tHello, World! From GHC " ++ formatVersion __GLASGOW_HASKELL__ ++ "\n"

-- Functions being used

formatVersion :: Int -> String
formatVersion v =
  let major = v `div` 100
      minor = v - (major * 100)
      patch = __GLASGOW_HASKELL_PATCHLEVEL1__
  in show major ++ "." ++ show minor ++ "." ++ show patch

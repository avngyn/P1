# Import
import numpy as np
import tensorflow as tf
import time

import P1

# Program configurations
GAME_NAME = "DiRT Rally"
FRAME_WIDTH = 640
FRAME_HEIGHT = 480
ENABLE_VIEW = False
FPS_DISPLAY_INTERVAL = 1.0

# Program keys
ACTIVATE_KEY = 0x14
EXIT_KEY = 0x51


# Game keys
ACCELERATE_KEY = 0x41
BRAKE_KEY = 0x21
LEFT_KEY = 0xBC
RIGHT_KEY = 0xBE

def main():
  # Initialize
  print("Finding {}...".format(GAME_NAME))
  status = P1.Initialize(GAME_NAME, FRAME_WIDTH, FRAME_HEIGHT, ENABLE_VIEW)
  isRunning = True
  if status != 0:
    print("Error: {}".format(status))
    isRunning = False
  else:
    print("Found {}!".format(GAME_NAME))

  # Main loop
  isActive = False
  activateKey_pressed = False
  tcount1 = 0.0
  while isRunning:
    # Check activate key
    if P1.GetKey(ACTIVATE_KEY) and activateKey_pressed == False:
      activateKey_pressed = True
      isActive = not isActive
      if isActive:
        print("AI is active")
      else:
        print("AI is paused")
    elif P1.GetKey(ACTIVATE_KEY) == 0:
      activateKey_pressed = False

    # Check exit key
    if P1.GetKey(EXIT_KEY):
      isRunning = False
      continue

    # Check if active
    if not isActive:
      continue

    # Get start time
    frameStartTime = time.time()

    # Capture frame
    frame = np.array(P1.Capture())

    # Send inputs to game
    P1.KeyPress(ACCELERATE_KEY)

    # Get end time
    frameEndTime = time.time()

    # Calculate FPS
    spf = frameEndTime - frameStartTime
    fps = 1.0/spf

    # Display FPS
    tcount1 += spf
    if tcount1 > FPS_DISPLAY_INTERVAL:
      print("FPS: {0:0.1f}".format(fps))
      tcount1 -= FPS_DISPLAY_INTERVAL

if __name__ == "__main__":
  main()
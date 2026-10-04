# Project Documentation: 2D Parking Simulation Game

## 1. Overview
This project is a 2D top-down car parking game developed in C++ using the Simple and Fast Multimedia Library (SFML). Players navigate a vehicle around an obstacle-filled parking lot to reach an assigned empty parking space as quickly as possible without crashing into parked vehicles.

---

## 2. Core Architecture & Modules

* **`main.cpp`**: Initializes random seed generation and runs the primary game loop through the `Game` class (`update()` and `render()`).
* **`Game` (`Game.cpp`)**: Central controller handling the window lifecycle (1764x990 resolution at 30 FPS), user inputs, collision detection, game state flow (`UI` states), and scoring.
* **`Car` (`Car.cpp`)**: Manages player vehicle physics, including acceleration, braking, natural deceleration, steering angles, turning radius calculation, screen boundary constraints, and vehicle color changes.
* **`Level` (`Level.cpp`)**: Handles the parking lot map, spawns 14 randomly colored parked cars across 15 possible parking bays, designates the remaining bay as the goal target, and tracks elapsed time.
* **`ParkedCar` (`ParkedCar.cpp`)**: Represents static vehicle obstacles with randomized colors and textures.
* **`MainMenu` (`MainMenu.cpp`)**: Main menu interface with interactive buttons to start the game, enter vehicle customization, or exit the application.
* **`CustomMenu` (`CustomMenu.cpp`)**: Vehicle customization screen allowing players to pick one of five car body colors (White, Green, Blue, Red, Black).

---

## 3. Game Mechanics & Controls

### Vehicle Controls
* **W / Up Arrow**: Accelerate forward (or brake if reversing).
* **S / Down Arrow**: Reverse / brake.
* **A / D**: Steer wheels left / right.
* **Space**: Handbrake / active deceleration.
* **F**: Print vehicle coordinates to console (debug feature).
* **Escape**: Return to the main menu from any screen or quit if pressed on the main menu.

### Rules & Scoring
* **Collisions**: Hitting a parked car reverts vehicle motion via `cancelMovement()` and deducts **20 points** per collision.
* **Goal & Victory**: Reaching the designated empty parking slot ends the level.
* **Score Calculation**: 
  $$\text{Final Score} = \max\left(0,\, 1000 - (\text{Elapsed Time in Seconds} \times 10) - \text{Penalties}\right)$$
  A lower completion time yields a higher final score.

---

## 4. Dependencies & Assets
* **Language & Framework**: C++, SFML (Graphics, Window, System).
* **Assets**:
  * **Textures**: Map background (`MAP1.png`), vehicle sprites (`BREAK.png`), parking goal marker (`FINISH.png`), UI menus/buttons (`PLAYBUTTON.png`, `CLOSEBUTTON.png`, `CUSTOMBUTTON.png`, `GAMEOVERBUTTON.png`, `LOGO.png`, `BG.png`), and color swatches.
  * **Fonts**: `Minecraftia-Regular.ttf` for on-screen timer and final score display.
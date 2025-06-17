| Component         | Details                                                                                                                   |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------- |
| **Secret Code**   | Random sequence of 4 characters from `['R', 'G', 'B', 'Y', 'O', 'P']`                                                     |
| **Player Guess**  | Client submits 4-letter guess like `RGBY`                                                                                 |
| **Feedback**      | Server responds with: <br> 🎯 **Black Pegs** – right color & position <br> ⚪ **White Pegs** – right color, wrong position |
| **Max Tries**     | 10 tries allowed                                                                                                          |
| **Win Condition** | 4 black pegs = guessed correctly                                                                                          |



[Client App] <--TCP--> [Server App]

Client:
  - Takes user input (guesses)
  - Sends to server
  - Displays server feedback
  - Shows win/loss status

Server:
  - Accepts connections
  - Generates secret code
  - Processes guesses and sends feedback
  - Ends game on win or after 10 attempts


Milestone Planning
| Milestone                | Description                                 |
| ------------------------ | ------------------------------------------- |
| ✅ Phase 1               | Plan structure, game rules, and protocol    |
| 🔜 Phase 2               | Setup basic TCP client-server communication |
| 🧠 Phase 3               | Implement Mastermind logic                  |
| 🧩 Phase 4               | Modularize client with command pattern      |
| 🧪 Phase 5               | Extend with UDP, scoreboard, etc.           |

Here's a Markdown-friendly version of your instructions:

markdown

### 🚀 How to Run the Project

1. **Download the code**

2. **Build the project using the Makefile**

   ```bash
   make
**This will compile the code and create the binaries in the build/ directory.**

3. **Run the server and client in separate terminals**

**Terminal 1 (Server):**

  ``` bash  ./build/server ```
 

**Terminal 2 (Client): **
  ``` bash ./build/client ```

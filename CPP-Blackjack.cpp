#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  // Seed the random number generator
  std::srand(std::time(0)); 
  // Starts the player's chip count
  int chips = 1000;
  // Instructions to the User of how to play the game
        std::cout << "Welcome to a game of Blackjack!" << "\n";
        std::cout << "The moves you can make are:" << ".\n";
        std::cout << "h = hit. Take another card from the Dealer" << ".\n";
        std::cout << "If you get 21 and the House does not, you win!  Careful! If your hand goes over 21 you lose!" << "\n";
        std::cout << "s = stand. Stop taking cards" << ".\n";
        std::cout << "You are betting that your hand will be closer to 21 before the House's hand busts, (goes over 21) or stands" << ".\n";
        std::cout << "You start with 1,000 Chips. Playing a round costs 100 Chips, winning a round gains you 200 chips" << ".\n";
        std::cout << "\n";

  // The Game repeats until the play runs out of chips or chooses to cash out
  char repeat;
  do {
    int player_score = 0;
    int dealer_score = 0;
    //checks to see if the player has enough chips to play another round, exits otherwise
    if (chips > 99) {
        chips -= 100;
    }
    else {
        std::cout << "Looks like Lady Luck wasn't with you tonight. You're don't have enough chips for the buy-in. Game Over."
        exit(0);
    }
    
    std::cout << "\n";
    std::cout << "You're current Chip total is: " << chips << ".\n";

    // Deal two cards to the player
    for (int i = 0; i < 2; i++) {
      int card = 2 + std::rand() % 10; // Generate a random card value between 2 and 11
      player_score += card;
      std::cout << "You were dealt a " << card << ". Your score is now " << player_score << ".\n";
    }

    // Deal one card to the dealer
    int card = 2 + std::rand() % 10;
    dealer_score += card;
    std::cout << "The dealer was dealt a " << card << ".\n";

    // Player's turn
    while (true) {
      std::cout << "Do you want to hit or stand? (h/s): ";
      char choice;
      std::cin >> choice;

      if (choice == 'h') {
        card = 2 + std::rand() % 10;
        player_score += card;
        std::cout << "You were dealt a " << card << ". Your score is now " << player_score << ".\n";

        if (player_score > 21) {
          std::cout << "You bust! Your score is " << player_score << ". The dealer wins.\n";
          break;
        }
      } else if (choice == 's') {
        std::cout << "You stand with a score of " << player_score << ".\n";
        break;
      } else {
        std::cout << "Invalid input. Please enter 'h' or 's'.\n";
      }
    }

    // Dealer's turn
    while (dealer_score < 17 && player_score <= 21) {
      card = 2 + std::rand() % 10;
      dealer_score += card;
      std::cout << "The dealer was dealt a " << card << ". The dealer's score is now " << dealer_score << ". You win 250 chips!\n";
    }

    if (dealer_score > 21) {
      chips += 200;
      std::cout << "The dealer busts! Your score is " << player_score << ". You win 200 chips!\n";
    } else if (dealer_score > player_score) {
      std::cout << "The dealer wins! Your score is " << player_score << ". The dealer's score is " << dealer_score << ".\n";
    } else if (dealer_score < player_score) {
      if (player_score = 21) {
        chips += 250;
        std::cout << "Blackjack! Your score is " << player_score << ". The dealer's score is " << dealer_score << " You win 250 chips!.\n";
      }
      else {
        chips += 200;
        std::cout << "You win! Your score is " << player_score << ". The dealer's score is " << dealer_score << " You win 200 chips!.\n";
      }
    } else {
      std::cout << "It's a tie! Your score is " << player_score << ". The dealer's score is " << dealer_score << ".\n";
    }

    // Ask if the user wants to play again
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> repeat;
  } while (repeat == 'y' || repeat == 'Y');
  std::cout << "You decided to cash out with: " << chips << " chips.  Thanks for playing!" 
  return 0;
}

#include "personagem.h"
using namespace std;

int round(Personagem *p, Personagem *inimigo, int round_atual) {
    printf("\nPlayer %d, escolha o que você irá fazer esse round: \n", p->getPlayer());
    std::cout << "1. Usar a arma " << p->getArma() << std::endl;
    std::cout << "2. Usar uma magia" << std::endl;
    std::cout << "3. Ver seus stats" << std::endl;
    std::cout << "4. Desistir da partida" << std::endl;
    int chance_kathos = dado(100, 1), max_decisao = 4;
    if (chance_kathos < 20) {
      max_decisao = 5;
    }
    if (max_decisao == 5) {
      std::cout << "5. EVENTO RARO! - Usar espada lendária Voto Solene de Bul-Kathos" << std::endl;
    }
    int decisao;
    printf("-> ");
    scanf("%d", &decisao);
    while (decisao < 1 || decisao > max_decisao) {
      printf("Selecione um valor válido: ");
      scanf("%d", &decisao);
    }

    while (decisao == 3) {
      p->printarStats();

      printf("\nPlayer %d, escolha o que você irá fazer esse round: \n", p->getPlayer());
      std::cout << "1. Usar a arma " << p->getArma() << std::endl;
      std::cout << "2. Usar uma magia" << std::endl;
      std::cout << "3. Ver seus stats" << std::endl;
      std::cout << "4. Desistir da partida" << std::endl;
      if (max_decisao == 5) {
        std::cout << "5. EVENTO RARO! - Usar espada lendária Voto Solene de Bul-Kathos" << std::endl;
      }

      printf("-> ");
      scanf("%d", &decisao);
      while (decisao < 1 || decisao > max_decisao) {
        printf("Selecione um valor válido: ");
        scanf("%d", &decisao);
      }
    }
    if (decisao == 1) {
      p->causarDanoFisico(inimigo);
    } else if (decisao == 2) {
      p->escolherMagia(inimigo);
    } else if (decisao == 4) {
      round_atual = -1;
      return round_atual;
    } else if (decisao == 5 && max_decisao == 5) {
      printf("BUL-KATHOOOOOOOOOOOOOOS!\n");
      p->bul_kathos(inimigo);
    }

    if (p->getHp() == 0 || inimigo->getHp() == 0) {
      printf("FIM DE JOGO!\n");
      round_atual = -1;
      return round_atual;
    }
    p->recuperarMana();
    return round_atual;
    
}

int main() {
  srand(time(NULL));


  //Menu
  printf("\n---RPG---\n");
  printf("ESCOLHA SUA CLASSE\n");
  printf("1. Guerreiro\n2. Ladrão\n3. Mago\n4. Paladino\n5. Animal\n6. Troll\n7. Dragão\n8. Zumbi\n");

  printf("Player 1: ");
  int player1;
  scanf("%d", &player1);
  while (player1 < 1 || player1 > 8) {
    printf("Digite um número de 1 a 8: ");
    scanf("%d", &player1);
  }

  printf("Player 2: ");
  int player2;
  scanf("%d", &player2);
  while (player2 < 1 || player2 > 8) {
    printf("Digite um número de 1 a 8: ");
    scanf("%d", &player2);
  }

  Personagem *p1, *p2;
  p1 = new Personagem(player1 - 1);
  p2 = new Personagem(player2 - 1);
  
  
  p1->printarStats();
  p2->printarStats();


  

  int round_atual = 1, gameOver = 0;
  while (round_atual != -1 && gameOver != 1) {
    printf("\n----------ROUND %d----------", round_atual);
    round_atual = round(p1, p2, round_atual);
    if (round_atual != -1) {
      round_atual = round(p2, p1, round_atual);
      if (round_atual == -1) {
        gameOver = 1;
      }
    } else {
      gameOver = 1;
    }
    round_atual++;
  }

  if (p1->getHp() == 0 && p2->getHp() != 0) {
    printf("VENCEDOR: Player 2! GGWP\n");
  } else if (p1->getHp() == 0 && p2->getHp() != 0) {
    printf("Vencedor: Player 1! GGWP\n");
  } 

}
#include "personagem.h"
using namespace std;

void round(Personagem *p, Personagem *inimigo, int round_atual) {
  printf("\n----------ROUND %d----------\n", round_atual);
    printf("Player %d, escolha o que você irá fazer esse round: \n", p->getPlayer());
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
    scanf("%d", &decisao);
    while (decisao < 1 || decisao > max_decisao) {
      printf("Selecione um valor válido: ");
      scanf("%d", &decisao);
    }

    while (decisao == 3) {
      p->printarStats();

      printf("DEBUG: DECISAO 3\n");
      printf("\nPlayer %d, escolha o que você irá fazer esse round: \n", p->getPlayer());
      std::cout << "1. Usar a arma " << p->getArma() << std::endl;
      std::cout << "2. Usar uma magia" << std::endl;
      std::cout << "3. Ver seus stats" << std::endl;
      std::cout << "4. Desistir da partida" << std::endl;
      if (max_decisao == 5) {
        std::cout << "5. EVENTO RARO! - Usar espada lendária Voto Solene de Bul-Kathos" << std::endl;
      }

      scanf("%d", &decisao);
      while (decisao < 1 || decisao > max_decisao) {
        printf("Selecione um valor válido: ");
        scanf("%d", &decisao);
      }
    }
    if (decisao == 1) {
      p->causarDanoFisico(inimigo);

      // dano *= p2->getRes_fisica() / 100;
      // int esquiva = dado(100, 1);
      // if (esquiva > p2->getAgilidade()) {
      //   std::cout << "ESQUIVA! O Player 2 conseguiu escapar do ataque do Player 1." << std::endl;
      // }
      // std::cout << "HIT! Player 1 atacou o Player 2 com sua arma " << p1->getArma() << ", causando " << dano << "pontos de dano." << std::endl;
      // p2->levarDanoFisico(dano);

    } else if (decisao == 2) {
      p->escolherMagia(inimigo);
    } else if (decisao == 4) {
      round_atual = -1;
    } else if (decisao == 5 && max_decisao == 5) {
      printf("BUL-KATHOS!\n");
      round_atual = -1;
      return;
    }

    if (p->getHp() == 0 || inimigo->getHp() == 0) {
      printf("FIM DE JOGO!\n");
      round_atual = -1;
      return;
    }
    if (round_atual == -1) {
      round_atual++;
    }
    
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
  while (round_atual != -1) {
    round(p1, p2, round_atual);
    if (round_atual != -1) {
      round(p2, p1, round_atual);
    }
  }
  

}
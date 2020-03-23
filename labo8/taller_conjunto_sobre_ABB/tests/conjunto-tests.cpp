#include "gtest-1.8.1/gtest.h"
#include "gtest-1.8.1/gtest.h"
#include "../src/Conjunto.h"


/**
 * Test simple básico
 */

TEST(conjunto_test, conjunto_vacio) {
   Conjunto<int> c;
   EXPECT_EQ(c.cardinal(), 0);
}


TEST(conjunto_test, test_insertar_un_valor) {
   Conjunto<int> c;
   c.insertar(5);
   EXPECT_EQ(c.cardinal(), 1);
}



TEST(conjunto_test, test_insertar_cinco_valores) {
   Conjunto<int> c;
   c.insertar(5);
   c.insertar(4);
   c.insertar(7);
   c.insertar(6);
   c.insertar(8);
   EXPECT_EQ(c.cardinal(), 5);
}


TEST(conjunto_test, test_pertenece) {
 Conjunto<int> c;

 for (int i = 0; i < 5; i++) {
   EXPECT_FALSE(c.pertenece(i));
 }

 // Agrego el 3
 c.insertar(3);
 for (int i = 0; i < 5; i++) {
   EXPECT_EQ(c.pertenece(i), i == 3);
 }

 // Agrego el 3
 c.insertar(5);
 for (int i = 0; i < 4; i++) {
   EXPECT_EQ(c.pertenece(i), i == 3);
 }
 EXPECT_TRUE(c.pertenece(5));

}


TEST(conjunto_test, test_insertar_remover_un_valor) {
   Conjunto<int> c;
   c.insertar(5);
   c.remover(5);
   EXPECT_EQ(c.cardinal(), 0);
   c.insertar(5);
   EXPECT_EQ(c.cardinal(), 1);
}



TEST(conjunto_test, test_minimo) {
   Conjunto<int> c;
   c.insertar(5);
   c.insertar(4);
   c.insertar(7);
   c.insertar(6);
   c.insertar(8);
   EXPECT_EQ(c.minimo(), 4);
}

TEST(conjunto_test, test_maximo) {
   Conjunto<int> c;
   c.insertar(5);
   c.insertar(4);
   c.insertar(7);
   c.insertar(6);
   c.insertar(8);
   EXPECT_EQ(c.maximo(), 8);
}



TEST(conjunto_test, test_remover_caso_un_hijo) {
Conjunto<int> c;
c.insertar(8);
c.insertar(17);
c.insertar(14);
c.insertar(13);
c.insertar(20);
c.insertar(18);
c.insertar(19);
c.insertar(25);
c.insertar(27);
c.insertar(26);
c.insertar(28);
c.insertar(1);
c.insertar(6);
c.insertar(3);
c.insertar(4);
c.insertar(7);
c.insertar(5);
c.insertar(8);
c.insertar(-3);
c.insertar(-4);
c.remover(8);
c.remover(13);
c.remover(18);
c.remover(1);
c.remover(4);
c.remover(26);
}




TEST(conjunto_test, test_remover_caso_dos_hijos_simple) {
   Conjunto<int> c;
   c.insertar(5);
   c.insertar(4);
   c.insertar(7);
   c.insertar(6);
   c.insertar(8);
   c.remover(7);
   EXPECT_EQ(c.cardinal(), 4);
   ASSERT_TRUE(c.pertenece(6));
   ASSERT_TRUE(c.pertenece(5));
   ASSERT_TRUE(c.pertenece(8));
   ASSERT_TRUE(c.pertenece(4));
   ASSERT_FALSE(c.pertenece(7));
   c.insertar(7);
   c.insertar(9);
   c.insertar(10);
   c.remover(8);
   ASSERT_TRUE(c.pertenece(7));
   ASSERT_TRUE(c.pertenece(9));
   ASSERT_TRUE(c.pertenece(10));
   ASSERT_FALSE(c.pertenece(8));
   c.insertar(5);
   c.insertar(9);
   c.insertar(15);
   c.insertar(0);
   c.insertar(-1);
   c.insertar(6575);
   c.insertar(675);
   c.insertar(-35);
   c.insertar(-7);
   c.insertar(65);
   c.insertar(9);
   c.remover(-35);
   c.remover(-7);
   c.remover(6575);
   c.remover(-0);
   c.remover(15);
}




TEST(conjunto_test, test_remover_caso_dos_hijos_doble) {
   Conjunto<int> c;
   c.insertar(5);
   c.insertar(4);
   c.insertar(20);
   c.insertar(15);
   c.insertar(12);
   c.insertar(16);
   c.insertar(24);
   c.insertar(22);
   c.insertar(25);
   c.remover(20);
   c.remover(5);
   c.remover(15);
   ASSERT_FALSE(c.pertenece(20));
   ASSERT_FALSE(c.pertenece(5));
   ASSERT_FALSE(c.pertenece(15));
   EXPECT_EQ(c.cardinal(), 6);
c.insertar(5);
c.insertar(9);
c.insertar(15);
c.insertar(0);
c.insertar(-1);
c.insertar(6575);
c.insertar(675);
c.insertar(-35);
c.insertar(-7);
c.insertar(65);
c.insertar(9);
c.remover(-35);
c.remover(-7);
c.remover(6575);
c.remover(-0);
c.remover(15);
}



TEST(conjunto_test, test_siguiente_inorder) {
   Conjunto<int> c;
   c.insertar(5);
   c.insertar(4);
   c.insertar(20);
   c.insertar(15);
   c.insertar(12);
   c.insertar(16);
   c.insertar(24);
   c.insertar(22);
   c.insertar(25);

   EXPECT_EQ(c.previo(20), 16);
   EXPECT_EQ(c.previo(5), 4);
   EXPECT_EQ(c.previo(16), 15);
}



const int NCLAVES = 1000;

int clave(int i) {
   return NCLAVES * ((i * i - 100 * i) % NCLAVES) + i;
}

TEST(conjunto_test, test_stress) {
   Conjunto<int> c;
   // Insertar
   for (int i = 0; i < NCLAVES; i++) {
       int k = clave(i);
       ASSERT_EQ(c.cardinal(), i);
       ASSERT_FALSE(c.pertenece(k));
       c.insertar(k);
       ASSERT_TRUE(c.pertenece(k));
   }
   ASSERT_EQ(c.cardinal(), NCLAVES);

   // Insertar de nuevo
   for (int i = 0; i < NCLAVES; i++) {
       int k = clave(i);
       ASSERT_TRUE(c.pertenece(k));
       c.insertar(k);
       ASSERT_TRUE(c.pertenece(k));
       ASSERT_EQ(c.cardinal(), NCLAVES);
   }

   // Eliminar los valores para i par
   for (int i = 0; i < NCLAVES; i++) {
       int k = clave(i);
       ASSERT_TRUE(c.pertenece(k));
       if (i % 2 == 0) {
           c.remover(k);
           ASSERT_FALSE(c.pertenece(k));
       }
   }
   ASSERT_EQ(c.cardinal(), NCLAVES / 2);

   // Eliminar los valores para i impar
   for (int i = 0; i < NCLAVES; i++) {
       int k = clave(i);
       if (i % 2 == 0) {
           ASSERT_FALSE(c.pertenece(k));
       } else {
           ASSERT_TRUE(c.pertenece(k));
           c.remover(k);
           ASSERT_FALSE(c.pertenece(k));
       }
   }
   ASSERT_EQ(c.cardinal(), 0);

   // Verificar que no haya valores
   for (int i = 0; i < NCLAVES; i++) {
       int k = clave(i);
       ASSERT_FALSE(c.pertenece(k));
   }

}

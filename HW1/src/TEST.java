import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author mathiaslindblom
 */
public class TEST {

    private int result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int lines = Integer.parseInt(br.readLine());
        int[][] cokeAndMOney = new int[lines][4];
        for (int i = 0; i < lines; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < 4; j++) {
                cokeAndMOney[i][j] = Integer.parseInt(line[j]);
            }
        }

        TEST test = new TEST();
        for (int i = 0; i < lines; i++) {
            int result = test.test(cokeAndMOney[i][0], cokeAndMOney[i][1], cokeAndMOney[i][2], cokeAndMOney[i][3], 0);
            System.out.println(result);
        }

    }

    public int test(int cokesLeft, int ones, int fives, int tens, int spendCoins) {
        result = 0;
        run(cokesLeft, ones, fives, tens, spendCoins);
        return result;
    }

    public void run(int cokesLeft, int ones, int fives, int tens, int spendCoins) {
        if(ones < 0 || fives < 0 || tens < 0) {
            throw new RuntimeException();
        }
        if(result != 0 && spendCoins + cokesLeft >= result) {
            return;
        }

        if (cokesLeft == 0) {
            if(result == 0 || spendCoins < result) {
                result = spendCoins;
            }
            return;
        }

        if(fives == 0 && tens == 0){
            run(0, ones - cokesLeft*8, fives, tens, spendCoins + 8*cokesLeft);
            return;
        }

        if(tens > 0) {
            run(cokesLeft - 1, ones + 2, fives, tens - 1, spendCoins + 1);
            if(ones > 2){
                run(cokesLeft - 1, ones - 3, fives + 1, tens - 1, spendCoins + 4);
            }
        }if(fives > 0) {
            if(ones > 2) {
                run(cokesLeft - 1, ones - 3, fives - 1, tens, spendCoins + 4);
            }
            if(fives > 1){
                run(cokesLeft - 1, ones + 2, fives - 2, tens, spendCoins + 2);
                if(ones > 2){
                    run(cokesLeft - 1, ones - 3, fives - 1, tens, spendCoins + 5);
                }
            }
        }
    }
}
 
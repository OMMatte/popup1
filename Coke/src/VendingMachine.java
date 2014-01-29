import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author mathiaslindblom
 */
public class VendingMachine {

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

        VendingMachine vm = new VendingMachine();
        for (int i = 0; i < lines; i++) {
            int result = vm.init(cokeAndMOney[i][0], cokeAndMOney[i][1], cokeAndMOney[i][2], cokeAndMOney[i][3], 0);
            System.out.println(result);
        }

    }

    public int init(int cokesLeft, int ones, int fives, int tens, int spendCoins) {
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

        if(tens >= cokesLeft) {
            run(0, ones, fives, tens - cokesLeft, spendCoins + cokesLeft);
            return;
        }else if (tens > 0) {
            if(tens + fives < cokesLeft && ones > 2){
                run(cokesLeft - 1, ones - 3, fives + 1, tens - 1, spendCoins + 4);
            } else {
                run(cokesLeft - 1, ones + 2, fives, tens - 1, spendCoins + 1);
            }

        } else if(fives > cokesLeft) {
            run(cokesLeft - 1, ones + 2, fives - 2, tens, spendCoins + 2);
        }else {
            run(cokesLeft - 1, ones - 3, fives - 1, tens, spendCoins + 4);
        }
        //            run(cokesLeft - 1, ones + 2, fives - 2, tens, spendCoins + 2);
        ////            run(cokesLeft - 1, ones - 3, fives - 1, tens, spendCoins + 4);
        //
        //        }else if (fives > 0 && ones > 2) {
        //            run(cokesLeft - 1, ones - 3, fives - 1, tens, spendCoins + 4);
        //        }
    }
}
 
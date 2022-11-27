#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for card number
    long number = 0;
    do
    {
        number = get_long("card number: ");
    }
    while (number < 1);

    // save as copy
    long originalnum = number;

    // Luhn’s Algorithm


// ~~Get Digits~~~
    int sumsum = 0;
    int prodsum = 0;

    while (number > 0)
    {
        // -----ADD ONLY Digits-----

        // Get last digit with modulo operation and store it as variable last
        int last = (number % 10);

        // print last digit
        // printf("curr digit to add last = %d\n", last);

        // add last digit to running sum
        sumsum += last;
        // printf("adding sum = %d\n", sumsum);

        // Move to next digit over
        // printf("current number = %ld\n", number);
        number /= 10;
        // printf("card num left = %ld\n", number);

        // -----MULTIPLY Digits-----

        if (number > 0)
        {
            // printf("still have numbers, need to multiply\n");

            // Get last digit with modulo operation and store it as variable lastt
            int lastt = (number % 10);

            // print last digit
            // printf("curr digit to multiply by 2 = %d\n", lastt);

            // multiply last digit by 2 and print
            int product = (2 * lastt);
            // printf("curr digit * 2 = %d\n", product);

            // if product > 9, modulo out before adding
            if (product > 9)
            {
                // printf("product > 9, splitting digits with modulo\n");

                // split last digit with modulo, save as var temp
                int temp = product % 10;
                // printf("temp value first digit = %d\n", temp);

                // divide product by 10 (move to next digit)
                product /= 10;
                // printf("second digit = %d\n", product);

                // sum and print both digits
                product += temp;
                // printf("sum of split digits = %d\n", product);
            }

            // add product to running sum of products

            prodsum += product;
            // printf("sum of the products = %d\n", prodsum);
            // printf("current number = %ld\n", number);
            number /= 10;
            // printf("card number left = %ld\n", number);
        }
    }

    // printf("\n\n\n\nfinished processing\n");
    int final = sumsum + prodsum;
    // printf("final number = %d\n", final);

    // check for type
    if (final % 10 == 0)
    {

        // printf("valid card number, check for type\n");
        // printf("%ld\n", originalnum);

        // Check for Mastercard
        string type = "";
        if (originalnum > 5099999999999999 && originalnum < 5600000000000000)
        {
            type = "MASTERCARD";
            printf("%s\n", type);
        }

        // Check for Amex
        else if ((originalnum > 339999999999999 && originalnum < 350000000000000) ||
                 (originalnum > 369999999999999 && originalnum < 3800000000000000))
        {
            type = "AMEX";
            printf("%s\n", type);
        }

        // Check for Visa
        else if ((originalnum > 3999999999999 && originalnum < 5000000000000) ||
                 (originalnum > 3999999999999999 && originalnum < 5000000000000000))
        {
            type = "VISA";
            printf("%s\n", type);
        }
        else // doesn't match any of the card types
        {
            type = "INVALID";
            printf("%s\n", type);
        }
    }
    else
    {
        printf("INVALID\n");
    } // card number is invalid

}

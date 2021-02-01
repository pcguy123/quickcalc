#include <iostream>
#include <vector>
#include <iterator>


bool isDec(char input[])
{
    if(input[0] == '0' && input[1] != 0)
    {
        return false;
    }
    
    int i;
    if(input[0] == '-')
    {
        if(input[1] == 0 || input[1] == '0')
        {
            return false;
        }
        i = 1;
    }
    else
    {
        i = 0;
    }
    
    for(; input[i] != 0; i++)
    {
        if(input[i] < '0' || input[i] > '9')
        {
            return false;
        }
    }
    return true;
}

bool isBin(char input[])
{
    int i;
    if(input[0] == '0' && input[1] == 'b' && input[2] != 0)
    {
        i = 2;
    }
    else if(input[0] == '-' && input[1] == '0' && input[2] == 'b' && input[3] != 0)
    {
        i = 3;
    }
    else
    {
        return false;
    }
    
    for(; input[i] != 0; i++)
    {
        if(input[i] != '0' && input[i] != '1')
        {
            return false;
        }
    }
    return true;
}

bool isHex(char input[])
{
    int i;
    if(input[0] == '0' && input[1] == 'x' && input[2] != 0)
    {
        i = 2;
    }
    else if(input[0] == '-' && input[1] == '0' && input[2] == 'x' && input[3] != 0)
    {
        i = 3;
    }
    else
    {
        return false;
    }
    
    for(; input[i] != 0; i++)
    {
        if(!((input[i] >= '0' && input[i] <= '9') ||
             (input[i] >= 'A' && input[i] <= 'F') ||
             (input[i] >= 'a' && input[i] <= 'f')))
        {
            return false;
        }
    }
    return true;
}

bool isOct(char input[])
{
    int i;
    if(input[0] == '0' && input[1] != 'x' && input[1] != 'b' && input[1] != 0)
    {
        i = 1;
    }
    else if(input[0] == '-' && input[1] == '0' && input[2] != 'x' && input[2] != 'b' &&
            input[2] != 0)
    {
        i = 2;
    }
    else
    {
        return false;
    }
    for(; input[i] != 0; i++)
    {
        if(i == 0 && input[i] == '-')
        {
            i++;
            continue;
        }
        if(input[i] < '0' || input[i] > '7')
        {
            return false;
        }
    }
    return true;
}

bool isOp(char input[])
{
    if(input[1] != 0 ||
       !((input[0] == '+') ||
       (input[0] == '-') ||
       (input[0] == '.') ||
       (input[0] == '*') ||
       (input[0] == '/')))
    {
        return false;
    }
    return true;
}

int toDec(char number[], int base)
{
    int total = 0;
    int i = 0;
    while(true)
    {
        if(number[i] == 0)
        {
            break;
        }
        i++;
    }
    
    int start = 0;
    if(number[0] == '-')
    {
        start++;
    }
    
    switch(base)
    {
        case(2):
            for(int j = 2 + start; j < i; j++)
            {
                total = total * 2 + (number[j] - '0');
            }
            break;
        case(8):
            for(int j = 1 + start; j < i; j++)
            {
                total = total * 8 + (number[j] - '0');
            }
            break;
        case(16):
            int val;
            for(int j = 2 + start; j < i; j++)
            {
                if(number[j] >= 'A' && number[j] <= 'F')
                {
                    val = number[j] - 'A' + 10;
                }
                else if(number[j] >= 'a' && number[j] <= 'f')
                {
                    val = number[j] - 'a' + 10;
                }
                else
                {
                    val = number[j] - '0';
                }
                total = total * 16 + val;
            }
            break;
        default:
            for(int j = start; j < i; j++)
            {
                total = total * 10 + (number[j] - '0');
            }
            break;
    }
    if(start != 0)
    {
        return -1 * total;
    }
    return total;
}

bool parseInput(char* input[], int count, std::vector<int>& nums, std::vector<char>& ops)
{
    if(count % 2 != 0)
    {
        std::cout << "Wrong number of terms.\n";
        return false;
    }
    for(int i = 1; i < count; i++)
    {
        if(i % 2 != 0)
        {
            if(isDec(input[i]))
            {
                nums.push_back(toDec(input[i], 10));
            }
            else if(isBin(input[i]))
            {
                nums.push_back(toDec(input[i], 2));
            }
            else if(isOct(input[i]))
            {
                nums.push_back(toDec(input[i], 8));
            }
            else if(isHex(input[i]))
            {
                nums.push_back(toDec(input[i], 16));
            }
            else if(isOp(input[i]))
            {
                std::cout << input[i] << " is an operator. A number belongs there.\n";
                return false;
            }
            else
            {
                std::cout << input[i] << " is unidentifiable. A number belongs there.\n";
                return false;
            }
        }
        else
        {
            if(isOp(input[i]))
            {
                ops.push_back(input[i][0]);
            }
            else if(isDec(input[i]) || isBin(input[i]) || isOct(input[i]) || isHex(input[i]))
            {
                std::cout << input[i] << " is a number, but an operator belongs there.\n";
                return false;
            }
            else
            {
                std::cout << input[i] << " is unidentifiable. An operator belongs there.\n";
                return false;
            }
        }
    }
    return true;
}

int evaluate(std::vector<int>& nums, std::vector<char>& ops)
{
    int total = nums[0];
    for(int i = 1; i < ops.size() + 1; i++)
    {
        switch(ops[i-1])
        {
            case('-'):
                total -= nums[i];
                break;
            case('.'):
                total *= nums[i];
                break;
            case('*'):
                total *= nums[i];
                break;
            case('/'):
                total /= nums[i];
                break;
            default:
                total += nums[i];
                break;
        }
    }
    return total;
}

void printHexResult(int val)
{
    if(val == 0)
    {
        std::cout << "Hex: 0x0\n";
    }
    else if(val < 0)
    {
        std::cout << "Hex: -0x" << std::hex << -1 * val << "\n";
    }
    else
    {
        std::cout << "Hex: 0x" << std::hex << val << "\n";
    }
}

void printOctResult(int val)
{
    if(val == 0)
    {
        std::cout << "Oct: 0\n";
    }
    else if(val < 0)
    {
        std::cout << "Oct: -0" << std::oct << -1 * val << "\n";
    }
    else
    {
        std::cout << "Oct: 0" << std::oct << val << "\n";
    }
}

void printBinResult(int val)
{
    if(val == 0)
    {
        std::cout << "Bin: 0b0\n";
        return;
    }
    else if (val < 0)
    {
        std::cout << "Bin: -0b";
        val *= -1;
    }
    else
    {
        std::cout << "Bin: 0b";
    }
    
    std::vector<short> bits;
    
    while(val != 0)
    {
        bits.push_back((short)(val % 2));
        val /= 2;
    }
    
    std::copy(bits.rbegin(), bits.rend(), std::ostream_iterator<short>(std::cout));
    std::cout << "\n";
}

void printResults(int result)
{
    std::cout << "Dec: " << result << "\n";
    printHexResult(result);
    printOctResult(result);
    printBinResult(result);
}

int main(int argc, char* argv[])
{
    std::vector<int> nums;
    std::vector<char> ops;
    if(!parseInput(argv, argc, nums, ops))
    {
        return EXIT_FAILURE;
    }
   
    int result = evaluate(nums, ops);
    
    printResults(result);
    
    return EXIT_SUCCESS;
}

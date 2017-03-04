#include<iostream>
#include<string>
#include<cstring>
#include<QString>
#include"mai.h"

using namespace std;
typedef unsigned int bit32;

class instruction{
private:
    bit32 binary_code;
    char* str_code;

    int str2bin_add(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 11;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != 0){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        binary += 0x20;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_sub(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 11;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != 0){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        binary += 0x22;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_slt(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 11;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != 0){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        binary += 0x2a;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_and(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 11;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != 0){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        binary += 0x24;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_or(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 11;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != 0){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        binary += 0x25;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_nor(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 11;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != 0){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        binary += 0x27;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_xor(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 11;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != 0){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        binary += 0x26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_addi(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        sscanf(in + p, "%d%c", &immediate);
        binary += immediate & 0xffff;
        binary += (0x8) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_slti(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        sscanf(in + p, "%d", &immediate);
        binary += immediate & 0xffff;
        binary += (0xa) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_andi(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        sscanf(in + p, "%d", &immediate);
        binary += immediate & 0xffff;
        binary += (0xc) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_ori(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        sscanf(in + p, "%d", &immediate);
        binary += immediate & 0xffff;
        binary += (0xd) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_xori(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        sscanf(in + p, "%d", &immediate);
        binary += immediate & 0xffff;
        binary += (0xe) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_lw(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp, *temp1;
        temp = (char*)calloc(7, 1);
        temp1 = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        sscanf(in + p, "%d(%s", &immediate,temp1);
        binary += immediate & 0xffff;
        i = 0;
        while (temp1[i] != ')'){
            temp[i] = temp1[i];
            i++;
            if (i > 6)break;
        }
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        binary += (0x23) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_sw(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp, *temp1;
        temp = (char*)calloc(7, 1);
        temp1 = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        sscanf(in + p, "%d(%s", &immediate, temp1);
        binary += immediate & 0xffff;
        i = 0;
        while (temp1[i] != ')'){
            temp[i] = temp1[i];
            i++;
            if (i > 6)break;
        }
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        binary += (0x2b) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_lb(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp, *temp1;
        temp = (char*)calloc(7, 1);
        temp1 = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        sscanf(in + p, "%d(%s", &immediate, temp1);
        binary += immediate & 0xffff;
        i = 0;
        while (temp1[i] != ')'){
            temp[i] = temp1[i];
            i++;
            if (i > 6)break;
        }
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        binary += (0x20) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_sb(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp, *temp1;
        temp = (char*)calloc(7, 1);
        temp1 = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        sscanf(in + p, "%d(%s", &immediate, temp1);
        binary += immediate & 0xffff;
        i = 0;
        while (temp1[i] != ')'){
            temp[i] = temp1[i];
            i++;
            if (i > 6)break;
        }
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        binary += (0x28) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_lui(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        sscanf(in + p, "%d", &immediate);
        binary += immediate & 0xffff;
        binary += (0xf) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_beq(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        sscanf(in + p, "%d", &immediate);
        binary += immediate & 0xffff;
        binary += (0x4) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_bne(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        p++;
        i = 0;
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 16;
        p++;
        sscanf(in + p, "%d", &immediate);
        binary += immediate & 0xffff;
        binary += (0x5) << 26;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    int str2bin_j(char* in){
        bit32 target, binary = 0;
        sscanf(in, "%d", &target);
        binary += target & 0x3fffff;
        binary += (0x2) << 26;
        this->binary_code = binary;
        binary_code2str_code();

        return 0;
    }

    int str2bin_jal(char* in){
        bit32 target, binary = 0;
        sscanf(in, "%d", &target);
        binary += target & 0x3fffff;
        binary += (0x3) << 26;
        this->binary_code = binary;
        binary_code2str_code();

        return 0;
    }

    int str2bin_jr(char* in){
        int i = 0, r, p = 0;
        bit32 binary = 0;
        int immediate = 0;
        char *temp;
        temp = (char*)calloc(7, 1);
        while (in[p] != ' '){
            temp[i] = in[p];
            i++;
            p++;
            if (i > 6)break;
        }
        temp[i] = 0;
        if ((r = read_register(temp)) == -1)return -1;
        binary += bit32(r) << 21;
        binary += 0x8;
        this->binary_code = binary;
        binary_code2str_code();


        return 0;
    }

    void binary_code2str_code(){
        char *str, *reg_1, *reg_2, *reg_3;
        bit32 op, func, reg1, reg2, reg3, target, immediateu;
        int immediate;
        str = (char*)calloc(30, 1);
        reg_1 = (char*)calloc(7, 1);
        reg_2 = (char*)calloc(7, 1);
        reg_3 = (char*)calloc(7, 1);
        op = (this->binary_code) >> 26;
        func = (this->binary_code) & 0x3f;
        reg1 = ((this->binary_code) >> 21) & 0x1f;
        reg2 = ((this->binary_code) >> 16) & 0x1f;
        reg3 = ((this->binary_code) >> 11) & 0x1f;
        reg_1 = get_register_name(reg1);
        reg_2 = get_register_name(reg2);
        reg_3 = get_register_name(reg3);
        immediateu = (this->binary_code) & 0xffff;
        immediate = (immediateu & 0x8000) ? -(0x10000-immediateu) : (immediateu & 0x7fff);
        target = (this->binary_code) & 0x3ffffff;
        switch (op){
        case 0:
            switch (func){
            case 0x20:
                sprintf(str, "add %s %s %s", reg_3, reg_1, reg_2); break;
            case 0x22:
                sprintf(str, "sub %s %s %s", reg_3, reg_1, reg_2); break;
            case 0x2a:
                sprintf(str, "slt %s %s %s", reg_3, reg_1, reg_2); break;
            case 0x24:
                sprintf(str, "and %s %s %s", reg_3, reg_1, reg_2); break;
            case 0x25:
                sprintf(str, "or %s %s %s", reg_3, reg_1, reg_2); break;
            case 0x27:
                sprintf(str, "nor %s %s %s", reg_3, reg_1, reg_2); break;
            case 0x26:
                sprintf(str, "xor %s %s %s", reg_3, reg_1, reg_2); break;
            case 0x8:
                sprintf(str, "jr %s", reg_1); break;
            default:
                sprintf(str, "hot hot hot"); break;
            }break;
        case 0x8:
            sprintf(str, "addi %s %s %d", reg_2, reg_1, immediate); break;
        case 0xa:
            sprintf(str, "slti %s %s %d", reg_2, reg_1, immediate); break;
        case 0xc:
            sprintf(str, "andi %s %s %d", reg_2, reg_1, immediate); break;
        case 0xd:
            sprintf(str, "ori %s %s %d", reg_2, reg_1, immediate); break;
        case 0xe:
            sprintf(str, "xori %s %s %d", reg_2, reg_1, immediate); break;
        case 0x4:
            sprintf(str, "beq %s %s %d", reg_1, reg_2, immediate); break;
        case 0x5:
            sprintf(str, "bne %s %s %d", reg_1, reg_2, immediate); break;
        case 0x23:
            sprintf(str, "lw %s %d(%s)", reg_2, immediate, reg_1); break;
        case 0x2b:
            sprintf(str, "sw %s %d(%s)", reg_2, immediate, reg_1); break;
        case 0x20:
            sprintf(str, "lb %s %d(%s)", reg_2, immediate, reg_1); break;
        case 0x28:
            sprintf(str, "sb %s %d(%s)", reg_2, immediate, reg_1); break;
        case 0xf:
            sprintf(str, "lui %s %d", reg_2, immediate); break;
        case 0x2:
            sprintf(str, "j %d", target); break;
        case 0x3:
            sprintf(str, "jal %d", target); break;
        default:
            sprintf(str, "hot hot hot"); break;
        }
        this->str_code = str;
    }

    char* get_register_name(bit32 reg){
        char* temp;
        temp = (char*)calloc(7, 1);
        switch (reg){
        case 0:strcpy(temp, "$zero"); break;
        case 1:strcpy(temp, "$at"); break;
        case 2:strcpy(temp, "$v0"); break;
        case 3:strcpy(temp, "$v1"); break;
        case 4:strcpy(temp, "$a0"); break;
        case 5:strcpy(temp, "$a1"); break;
        case 6:strcpy(temp, "$a2"); break;
        case 7:strcpy(temp, "$a3"); break;
        case 8:strcpy(temp, "$t0"); break;
        case 9:strcpy(temp, "$t1"); break;
        case 10:strcpy(temp, "$t2"); break;
        case 11:strcpy(temp, "$t3"); break;
        case 12:strcpy(temp, "$t4"); break;
        case 13:strcpy(temp, "$t5"); break;
        case 14:strcpy(temp, "$t6"); break;
        case 15:strcpy(temp, "$t7"); break;
        case 16:strcpy(temp, "$s0"); break;
        case 17:strcpy(temp, "$s1"); break;
        case 18:strcpy(temp, "$s2"); break;
        case 19:strcpy(temp, "$s3"); break;
        case 20:strcpy(temp, "$s4"); break;
        case 21:strcpy(temp, "$s5"); break;
        case 22:strcpy(temp, "$s6"); break;
        case 23:strcpy(temp, "$s7"); break;
        case 24:strcpy(temp, "$t8"); break;
        case 25:strcpy(temp, "$t9"); break;
        case 26:strcpy(temp, "$k0"); break;
        case 27:strcpy(temp, "$k1"); break;
        case 28:strcpy(temp, "$gp"); break;
        case 29:strcpy(temp, "$sp"); break;
        case 30:strcpy(temp, "$fp"); break;
        case 31:strcpy(temp, "$ra"); break;
        default:strcpy(temp, "???"); break;
        }
        return temp;
    }

    int read_register(char* reg){
        if (!strcmp(reg, "$0"))return 0;
        else if (!strcmp(reg, "$1"))return 1;
        else if (!strcmp(reg, "$2"))return 2;
        else if (!strcmp(reg, "$3"))return 3;
        else if (!strcmp(reg, "$4"))return 4;
        else if (!strcmp(reg, "$5"))return 5;
        else if (!strcmp(reg, "$6"))return 6;
        else if (!strcmp(reg, "$7"))return 7;
        else if (!strcmp(reg, "$8"))return 8;
        else if (!strcmp(reg, "$9"))return 9;
        else if (!strcmp(reg, "$10"))return 10;
        else if (!strcmp(reg, "$11"))return 11;
        else if (!strcmp(reg, "$12"))return 12;
        else if (!strcmp(reg, "$13"))return 13;
        else if (!strcmp(reg, "$14"))return 14;
        else if (!strcmp(reg, "$15"))return 15;
        else if (!strcmp(reg, "$16"))return 16;
        else if (!strcmp(reg, "$17"))return 17;
        else if (!strcmp(reg, "$18"))return 18;
        else if (!strcmp(reg, "$19"))return 19;
        else if (!strcmp(reg, "$20"))return 20;
        else if (!strcmp(reg, "$21"))return 21;
        else if (!strcmp(reg, "$22"))return 22;
        else if (!strcmp(reg, "$23"))return 23;
        else if (!strcmp(reg, "$24"))return 24;
        else if (!strcmp(reg, "$25"))return 25;
        else if (!strcmp(reg, "$26"))return 26;
        else if (!strcmp(reg, "$27"))return 27;
        else if (!strcmp(reg, "$28"))return 28;
        else if (!strcmp(reg, "$29"))return 29;
        else if (!strcmp(reg, "$30"))return 30;
        else if (!strcmp(reg, "$31"))return 31;
        else if (!strcmp(reg, "$zero"))return 0;
        else if (!strcmp(reg, "$at"))return 1;
        else if (!strcmp(reg, "$v0"))return 2;
        else if (!strcmp(reg, "$v1"))return 3;
        else if (!strcmp(reg, "$a0"))return 4;
        else if (!strcmp(reg, "$a1"))return 5;
        else if (!strcmp(reg, "$a2"))return 6;
        else if (!strcmp(reg, "$a3"))return 7;
        else if (!strcmp(reg, "$t0"))return 8;
        else if (!strcmp(reg, "$t1"))return 9;
        else if (!strcmp(reg, "$t2"))return 10;
        else if (!strcmp(reg, "$t3"))return 11;
        else if (!strcmp(reg, "$t4"))return 12;
        else if (!strcmp(reg, "$t5"))return 13;
        else if (!strcmp(reg, "$t6"))return 14;
        else if (!strcmp(reg, "$t7"))return 15;
        else if (!strcmp(reg, "$s0"))return 16;
        else if (!strcmp(reg, "$s1"))return 17;
        else if (!strcmp(reg, "$s2"))return 18;
        else if (!strcmp(reg, "$s3"))return 19;
        else if (!strcmp(reg, "$s4"))return 20;
        else if (!strcmp(reg, "$s5"))return 21;
        else if (!strcmp(reg, "$s6"))return 22;
        else if (!strcmp(reg, "$s7"))return 23;
        else if (!strcmp(reg, "$t8"))return 24;
        else if (!strcmp(reg, "$t9"))return 25;
        else if (!strcmp(reg, "$k0"))return 26;
        else if (!strcmp(reg, "$k1"))return 27;
        else if (!strcmp(reg, "$gp"))return 28;
        else if (!strcmp(reg, "$sp"))return 29;
        else if (!strcmp(reg, "$fp"))return 30;
        else if (!strcmp(reg, "$ra"))return 31;
        else return -1;
    }

public:
    instruction(){
        binary_code = 0;
        str_code = 0;
    }

    bit32 get_binary_code(){
        return binary_code;
    }

    char* get_str_code(){
        return str_code;
    }

    char* C_str_binary_code(){
        char *temp;
        int value[8];
        temp = (char*)calloc(15, 1);
        value[0] = ((this->binary_code) >> 28) & 0xf;
        value[1] = ((this->binary_code) >> 24) & 0xf;
        value[2] = ((this->binary_code) >> 20) & 0xf;
        value[3] = ((this->binary_code) >> 16) & 0xf;
        value[4] = ((this->binary_code) >> 12) & 0xf;
        value[5] = ((this->binary_code) >> 8) & 0xf;
        value[6] = ((this->binary_code) >> 4) & 0xf;
        value[7] = (this->binary_code) & 0xf;
        sprintf(temp, "0x%x%x%x%x%x%x%x%x", value[0], value[1], value[2], value[3], value[4], value[5], value[6], value[7]);
        return temp;
    }

    int input_instruction_str(char* in){
        int i = 0;
        char *temp;
        temp = (char*)calloc(6, 1);
        while (in[i] != ' '){
            temp[i] = in[i];
            i++;
            if (i > 5)break;
        }
        temp[i] = 0;
        if (!strcmp(temp, "add"))return str2bin_add(in + 4);
        else if (!strcmp(temp, "sub"))return str2bin_sub(in + 4);
        else if (!strcmp(temp, "slt"))return str2bin_slt(in + 4);
        else if (!strcmp(temp, "and"))return str2bin_and(in + 4);
        else if (!strcmp(temp, "or"))return str2bin_or(in + 3);
        else if (!strcmp(temp, "nor"))return str2bin_nor(in + 4);
        else if (!strcmp(temp, "xor"))return str2bin_xor(in + 4);
        else if (!strcmp(temp, "addi"))return str2bin_addi(in + 5);
        else if (!strcmp(temp, "slti"))return str2bin_slti(in + 5);
        else if (!strcmp(temp, "andi"))return str2bin_andi(in + 5);
        else if (!strcmp(temp, "ori"))return str2bin_ori(in + 4);
        else if (!strcmp(temp, "xori"))return str2bin_xori(in + 5);
        else if (!strcmp(temp, "lw"))return str2bin_lw(in + 3);
        else if (!strcmp(temp, "sw"))return str2bin_sw(in + 3);
        else if (!strcmp(temp, "lb"))return str2bin_lb(in + 3);
        else if (!strcmp(temp, "sb"))return str2bin_sb(in + 3);
        else if (!strcmp(temp, "lui"))return str2bin_lui(in + 4);
        else if (!strcmp(temp, "beq"))return str2bin_beq(in + 4);
        else if (!strcmp(temp, "bne"))return str2bin_bne(in + 4);
        else if (!strcmp(temp, "j"))return str2bin_j(in + 2);
        else if (!strcmp(temp, "jal"))return str2bin_jal(in + 4);
        else if (!strcmp(temp, "jr"))return str2bin_jr(in + 3);
        else return -1;
    }

    int input_instruction_binary(bit32 code){
        this->binary_code = code;
        binary_code2str_code();
    }
};

QString dodo(QString instring){
    instring = instring.simplified();
    string o;
    char*s=(char*)calloc(30, 1);
    QByteArray ba = instring.toLatin1();
    s=ba.data();
        instruction t;
        if (t.input_instruction_str(s) == -1){
            o +="Wrong input!";
        }
        else
        {
        string ast=t.C_str_binary_code();
        //string fn=t.get_str_code();;
        o=ast;
        }

    QString qo = QString::fromStdString(o);
    return qo;
}
QString odod(QString instring){
    string o;
    bool ok;
    bit32 s=instring.toUInt(&ok,16);
        instruction t;
        if (t.input_instruction_binary(s) == -1){
            o +="Wrong input!";
        }
        else
        {
        //string ast=t.C_str_binary_code();
        string fn=t.get_str_code();;
        o=fn;
        }

    QString qo = QString::fromStdString(o);
    return qo;
}

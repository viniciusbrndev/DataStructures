void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs,
              TipoArea Area, int Esq, int Dir, int *i, int *j)
{
    int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq;
    int NRArea = 0;
    
    /* ALTERADO: Inicialização dos limites invertida para ordenação decrescente */
    int Linf = INT_MAX; 
    int Lsup = INT_MIN; 
    
    short OndeLer = TRUE; 
    TipoRegistro UltLido, R;

    fseek(*ArqLi, (Li - 1) * sizeof(TipoRegistro), SEEK_SET);
    fseek(*ArqEi, (Ei - 1) * sizeof(TipoRegistro), SEEK_SET);
    *i = Esq - 1; 
    *j = Dir + 1;

    while (Ls >= Li)
    {
        if (NRArea < TAMAREA - 1)
        {
            if (OndeLer) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
            else Lelnf(ArqLi, &UltLido, &Li, &OndeLer);
            
            InserirArea(&Area, &UltLido, &NRArea);
            continue;
        }

        if (Ls == Es) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
        else if (Li == Ei) Lelnf(ArqLi, &UltLido, &Li, &OndeLer);
        else if (OndeLer) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
        else Lelnf(ArqLi, &UltLido, &Li, &OndeLer);

        /* ALTERADO: Elemento menor que Lsup vai para A2 (direita - Es) */
        if (UltLido.Chave < Lsup)
        {
            *j = Es; 
            EscreveMax(ArqLEs, UltLido, &Es);
            continue;
        }

        /* ALTERADO: Elemento maior que Linf vai para A1 (esquerda - Ei) */
        if (UltLido.Chave > Linf)
        {
            *i = Ei; 
            EscreveMin(ArqEi, UltLido, &Ei);
            continue;
        }

        InserirArea(&Area, &UltLido, &NRArea);

        /* Regra do subarquivo de menor tamanho */
        if (Ei - Esq < Dir - Es)
        {
            /* ALTERADO: Para A1 ser decrescente, retira-se o MAIOR da área */
            RetiraMax(&Area, &R, &NRArea);
            EscreveMin(ArqEi, R, &Ei); 
            Linf = R.Chave;
        }
        else 
        {
            /* ALTERADO: Para A2 ser decrescente, retira-se o MENOR da área */
            RetiraMin(&Area, &R, &NRArea);
            EscreveMax(ArqLEs, R, &Es); 
            Lsup = R.Chave;
        }
    }

    /* Esvaziamento final da área de memória para A1 */
    while (Ei <= Es)
    {
        /* ALTERADO: Descarrega da área do MAIOR para o MENOR para manter a ordem decrescente */
        RetiraMax(&Area, &R, &NRArea);
        EscreveMin(ArqEi, R, &Ei);
    }
}
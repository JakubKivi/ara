/*
    Pionek          - pawn
    Duch            - ghost
    Kawaleria       - cav
    Kr�l            - king
    Wie�a           - tower
    Szar�a          - charge
    Zagadka         - mystery

    pole przepa�ci  - notexist
    polec puste     - empty
    przepa��        -abyss
*/
int abs(int x){
    return x > 0 ? x: -x;
}


bool CanMove(Pole board[17][34], int x, int y, int targetX, int targetY){
    if(board[x][y].name=="charge"){
        if(board[targetX][targetY].name=="empty"){
            if( y==targetY && abs(targetX-x)==2 ) return 1;
            if( x==targetX){
                for(int i=y; i<targetY; )
            }
        }

        }else return 0;



    if(board[x][y].name=="tower"){
         if(board[targetX][targetY].name=="empty") return 1;

         else return 0;
    }


}

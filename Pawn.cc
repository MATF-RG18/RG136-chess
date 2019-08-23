#include "chess.hpp"

//Constructors
Pawn::Pawn(PlayerColor color, int file, int rank) : ChessPiece(color,file,rank){}

Pawn::Pawn(PlayerColor color, Field* field) : ChessPiece(color,field){}

//Chess Related
list<Field*> Pawn::getPlayableMoves(Chessboard cb){
	//TODO: Move would open check

	list<Field*> res;
	Field* field;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			field = new Field(i,j);
			if(checkIfLegal(*field, cb)){
				res.push_back(field);
			}
			else delete field;
		}
	}
	return res;
}

bool Pawn::checkIfLegal(Field field, Chessboard cb){
	int rankDiff = abs(field.rank - this->field->rank);
	int fileDiff = abs(field.file - this->field->file);

		 //moving forward one square or eating
	if(( (rankDiff==1 && fileDiff<=1)
		 //moving forward two squares if at starting position
		 || (rankDiff==2 && field.file == this->field->file && this->field->rank==1)
		 //en passant
		 || (cb.pawnMovedLast != nullptr 
		 	 && *(cb.pawnMovedLast->field) == field
		 	 && cb.pawnMovedLast->field->rank == this->field->rank
		 	 && (cb.pawnMovedLast->field->file - this->field->file) == 1) )
		&& !friendlyPieceOnField(field,cb)){
		
		return true;
	}
	return false;
}

//Utility
string Pawn::toString() const{
	string res = "p";
	return res;
}

//Display
void Pawn::display(int file, int rank){
	glPushMatrix();
		if(this->getColor()==PlayerColor::White){
			glColor3f( 0.9, 0.8, 0.7 );
		}
		else{
			glColor3f( 0.3, 0.2, 0.1 );
		}
	
		if(this->getColor()==PlayerColor::White){
			glColor3f( 0.9, 0.8, 0.7 );
		}
		else{
			glColor3f( 0.3, 0.2, 0.1 );
		}
	    glTranslatef(-3.5+file,-3.5+rank,10);
	    glutSolidSphere(0.3, 20, 20);
	glPopMatrix();
}
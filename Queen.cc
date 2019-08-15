#include "chess.hpp"

//Constructors
Queen::Queen(PlayerColor color, int file, int rank) : ChessPiece(color,file,rank){}

Queen::Queen(PlayerColor color, Field* field) : ChessPiece(color,field){}

//Chess Related
list<Field*> Queen::getPlayableMoves(Chessboard cb){
	//TODO: Move would open check
	list<Field*> res;
	Field* field;

	//moving horizontally
	for(int i=this->field->rank-1; i>0; i--){
		field = new Field(this->field->file, i);
		if(!ChessPiece::fieldAttackedOrOccupied(*field,cb))
			break;
		res.push_back(field);
	}
	for(int i=this->field->rank+1; i<8; i++){
		field = new Field(this->field->file, i);
		if(!ChessPiece::fieldAttackedOrOccupied(*field,cb))
			break;
		res.push_back(field);
	}

	//moving vertically
	for(int i=this->field->file-1; i>0; i--){
		field = new Field(i, this->field->rank);
		if(!ChessPiece::fieldAttackedOrOccupied(*field,cb))
			break;
		res.push_back(field);
	}
	for(int i=this->field->file+1; i<8; i++){
		field = new Field(i, this->field->rank);
		if(!ChessPiece::fieldAttackedOrOccupied(*field,cb))
			break;
		res.push_back(field);
	}


	//moving diagonally

	bool pieceLeft = false;
	bool pieceRight = false;
	for(int i=this->field->rank-1; i>0; i--){

		if(this->field->file-i >= 0 && !pieceLeft){
			field = new Field(this->field->file-i,i);
			if(!ChessPiece::friendlyPieceOnField(*field,cb))
				res.push_back(field);
			else
				pieceLeft = true;
		}

		if(this->field->file+i < 8 && !pieceRight){
			field = new Field(this->field->file+i,i);
			if(!(ChessPiece::friendlyPieceOnField(*field,cb)))
				res.push_back(field);
			else
				pieceRight = true;
		}
	}

	pieceLeft = false;
	pieceRight = false;
	for(int i=this->field->rank+1; i<8; i++){

		if(this->field->file-i >= 0 && !pieceLeft){
			field = new Field(this->field->file-i,i);
			if(!(ChessPiece::friendlyPieceOnField(*field,cb)))
				res.push_back(field);
			else
				pieceLeft = true;
		}

		if(this->field->file+i < 8 && !pieceRight){
			field = new Field(this->field->file+i,i);
			if(!(ChessPiece::friendlyPieceOnField(*field,cb)))
				res.push_back(field);
			else
				pieceRight = true;
		}
	}

	return res;
}

bool Queen::checkIfLegal(Field field, Chessboard cb){
	list<Field*> playable = this->getPlayableMoves(cb);
	for(Field* move : playable){
		if(*move == field){
			return true;
		}
	}
	return false;
}

//Utility
string Queen::toString() const{
	string res = "Q";
	return res;
}
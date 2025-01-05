;Read all addressing blocks in turn
;Assembles into a binary file two bytes short of 16KB
;Burn to a 27C128 or 256 (top half) and insert in place of M0
DESTRAM = $0001

 .org $C000
Loop:
  LDA $0000  ;M3 (RAM)
  STA DESTRAM  
  LDA $2000  ;M2 (RAM)
  STA DESTRAM
  LDA $8000  ;M1 (ROM)
  STA DESTRAM
  LDA $C000  ;M0 (ROM)
  STA DESTRAM
  LDA $D000  ;BLK0
  STA DESTRAM
  LDA $E000  ;M0
  STA DESTRAM
  LDA $F800  ;IO
  STA DESTRAM
  LDA $FF00  ;M0
  STA DESTRAM
  NOP		 ;Four NOPs to easily identify the start/end
  NOP
  NOP
  NOP
  BNE Loop

.org $FFFC
  .WORD $C000
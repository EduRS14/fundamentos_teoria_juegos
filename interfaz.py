from tkinter import *
import os
from PIL import ImageTk, Image

raiz = Tk()

raiz.title("Interfaz gráfica")
raiz.resizable(False, False)
raiz.iconbitmap("carburito.ico")
raiz.geometry("800x600")
raiz.config(bg = "sky blue")

frame1 = Frame(raiz)

#frame1.pack(side = "left", anchor = "n")
#frame1.pack(fill="both", expand="True")
frame1.config(bg = "white")
frame1.config(width = "500", height = "400")
frame1.config(bd =  5)  
frame1.config(relief = "ridge")
frame1.config(cursor="hand2")
frame1.place(x = 150, y = 100)

label1 = Label(frame1, text = "Hola a todos!", fg = "red", font = ("Comic Sans MS", 20))
label1.place(x = 170, y = 180)

imagen = ImageTk.PhotoImage(Image.open("carburo.png").resize((100,100)))
Label(frame1, image = imagen).place(x = 0, y = 0)

raiz.mainloop() 
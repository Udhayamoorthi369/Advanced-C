### What is RISC and CISC Architectures?
* A complex instruction set computer is a computer where single instructions can perform numerous low-level operations like a load from memory, an arithmetic operation, and a memory store or are accomplished by multi-step processes or addressing modes in single instructions, as its name proposes “Complex Instruction Set ”.

* A reduced instruction set computer is a computer that only uses simple commands that can be divided into several instructions which achieve low-level operation within a single CLK cycle, as its name proposes “Reduced Instruction Set ”


## RISC Architecture
* The term RISC stands for ‘’Reduced Instruction Set Computer’’. It is a CPU design plan based on simple orders and acts fast.

* This is a small or reduced set of instructions. Here, every instruction is expected to attain very small jobs. In this machine, the instruction sets are modest and simple, which help in comprising more complex commands. Each instruction is about a similar length; these are wound together to get compound tasks done in a single operation. Most commands are completed in one machine cycle. This pipelining is a crucial technique used to speed up RISC machines.

![RISC-Architecture](https://user-images.githubusercontent.com/89963356/135193054-b8bef425-4efe-448d-9493-ab67ed9785bc.jpg)

* Reduced Instruction Set Computer is a microprocessor that is designed to carry out few instructions at a similar time. Based on small commands, these chips need fewer transistors, which makes the transistors inexpensive to design and produce. The features of RISC include the following
 
* The demand for decoding is less
* Few data types in hardware
* General-purpose register Identical
* Uniform instruction set
* Simple addressing nodes
* Also, while writing a program, RISC makes it easier by letting the computer programmer eliminate needless codes and stops wasting cycles.

## Characteristics
The characteristics of RISC architecture include the following.

* Simple Instructions are used in RISC architecture.
* RISC helps and supports few simple data types and synthesizes complex data types.
* RISC utilizes simple addressing modes and fixed-length instructions for pipelining.
* RISC permits any register to use in any context.
* One Cycle Execution Time
* The amount of work that a computer can perform is reduced by separating “LOAD” and “STORE” instructions.
* RISC contains a Large Number of Registers to prevent various interactions with memory.
* In RISC, Pipelining is easy as the execution of all instructions will be done in a uniform interval of time i.e. one click.
* In RISC, more RAM is required to store assembly-level instructions.
* Reduced instructions need a less number of transistors in RISC.
* RISC uses the Harvard memory model means it is Harvard Architecture.
* A compiler is used to perform the conversion operation means converting a high-level language statement into the code of its form.

## CISC Architecture
* The term CISC stands for ‘’Complex Instruction Set Computer’’. It is a CPU design plan based on single commands, which are skilled in executing multi-step operations.
* CISC computers have small programs. It has a huge number of compound instructions, which take a long time to perform. Here, a single set of instructions is protected in several steps; each instruction set has an additional than 300 separate instructions. Maximum instructions are finished in two to ten machine cycles. In CISC, instruction pipelining is not easily implemented..
![CISC-Architecture](https://user-images.githubusercontent.com/89963356/135193350-3e9df25c-d23d-4fb8-8140-5d6a3d45c591.jpg)
* The CISC machines have good acts, based on the overview of program compilers; as the range of innovative instructions are simply obtainable in one instruction set. They design compound instructions in a single, simple set of instructions.

They achieve low-level processes, which makes it easier to have huge addressing nodes and additional data types in the hardware of a machine. But, CISC is considered less efficient than RISC, because of its incompetence to eliminate codes which leads to wasting of cycles. Also, microprocessor chips are difficult to understand and program for, because of the complexity of the hardware.
## Characteristics
The characteristics of CISC architecture include the following.

* Instruction-decoding logic will be Complex.
* One instruction is required to support multiple addressing modes.
* Less chip space is enough for general purpose registers for the instructions that are 0operated directly on memory.
* Various CISC designs are set up with two special registers for the stack pointer, handling interrupts,  etc.
* MUL is referred to as a “complex instruction
## Comparison Between RISC and CISC
* RISC stands for ‘Reduced Instruction Set Computer Whereas, CISC stands for Complex Instruction Set Computer. The RISC processors have a smaller set of instructions with few addressing nodes. The CISC processors have a larger set of instructions with many addressing nodes.

![RISC-Vs-CISC](https://user-images.githubusercontent.com/89963356/135193506-cf80a9d8-51a3-4bb4-a9e7-b3d156aa736d.jpg)

### Different Types of RAM (Random Access Memory )

# RAM(Random Access Memory) 
 * RAM is a part of computer's Main Memory which is directly accessible by CPU. RAM is used to Read and Write data into it which is accessed by CPU randomly. RAM is volatile in nature, it means if the power goes off, the stored information is lost. RAM is used to store the data that is currently processed by the CPU. Most of the programs and data that are modifiable are stored in RAM. Integrated RAM chips are available in two form: 

# SRAM(Static RAM)
# DRAM(Dynamic RAM)

The block diagram of RAM chip is given below.  
![RAM](https://user-images.githubusercontent.com/89963356/135195625-fc4a2c17-bdbd-45fc-82b1-f29d59aa8fd2.png)


# SRAM :
* The SRAM memories consist of circuits capable of retaining the stored information as long as the power is applied. That means this type of memory requires constant power. SRAM memories are used to build Cache Memory. SRAM Memory Cell: Static memories(SRAM) are memories that consist of circuits capable of retaining their state as long as power is on. Thus this type of memories is called volatile memories. The below figure shows a cell diagram of SRAM. A latch is formed by two inverters connected as shown in the figure. Two transistors T1 and T2 are used for connecting the latch with two bit lines. The purpose of these transistors is to act as switches that can be opened or closed under the control of the word line, which is controlled by the address decoder. When the word line is at 0-level, the transistors are turned off and the latch remains its information. For example, the cell is at state 1 if the logic value at point A is 1 and at point B is 0. This state is retained as long as the word line is not activated.  

![SRAM](https://user-images.githubusercontent.com/89963356/135195711-19723966-4d49-401a-80a3-ba5f4a45bb36.png)


* For Read operation, the word line is activated by the address input to the address decoder. The activated word line closes both the transistors (switches) T1 and T2. Then the bit values at points A and B can transmit to their respective bit lines. The sense/write circuit at the end of the bit lines sends the output to the processor. For Write operation, the address provided to the decoder activates the word line to close both the switches. Then the bit value that to be written into the cell is provided through the sense/write circuit and the signals in bit lines are then stored in the cell.  

# DRAM :
* DRAM stores the binary information in the form of electric charges that applied to capacitors. The stored information on the capacitors tend to lose over a period of time and thus the capacitors must be periodically recharged to retain their usage. The main memory is generally made up of DRAM chips. DRAM Memory Cell: Though SRAM is very fast, but it is expensive because of its every cell requires several transistors. Relatively less expensive RAM is DRAM, due to the use of one transistor and one capacitor in each cell, as shown in the below figure., where C is the capacitor and T is the transistor. Information is stored in a DRAM cell in the form of a charge on a capacitor and this charge needs to be periodically recharged. For storing information in this cell, transistor T is turned on and an appropriate voltage is applied to the bit line. This causes a known amount of charge to be stored in the capacitor. After the transistor is turned off, due to the property of the capacitor, it starts to discharge. Hence, the information stored in the cell can be read correctly only if it is read before the charge on the capacitors drops below some threshold value.  


![DRAM](https://user-images.githubusercontent.com/89963356/135195786-c6bea345-e5f0-47e6-b2fc-8b6d108a7640.png)

 

## Types of DRAM :There are mainly 5 types of DRAM:  

# Asynchronous DRAM (ADRAM): 
* The DRAM described above is the asynchronous type DRAM. The timing of the memory device is controlled asynchronously. A specialized memory controller circuit generates the necessary control signals to control the timing. The CPU must take into account the delay in the response of the memory. 
# Synchronous DRAM (SDRAM): 
* These RAM chips' access speed is directly synchronized with the CPU's clock. For this, the memory chips remain ready for operation when the CPU expects them to be ready. These memories operate at the CPU-memory bus without imposing wait states. SDRAM is commercially available as modules incorporating multiple SDRAM chips and forming the required capacity for the modules. 
# Double-Data-Rate SDRAM (DDR SDRAM): * 
This faster version of SDRAM performs its operations on both edges of the clock signal; whereas a standard SDRAM performs its operations on the rising edge of the clock signal. Since they transfer data on both edges of the clock, the data transfer rate is doubled. To access the data at high rate, the memory cells are organized into two groups. Each group is accessed separately. 
# Rambus DRAM (RDRAM): 
* The RDRAM provides a very high data transfer rate over a narrow CPU-memory bus. It uses various speedup mechanisms, like synchronous memory interface, caching inside the DRAM chips and very fast signal timing. The Rambus data bus width is 8 or 9 bits. 
# Cache DRAM (CDRAM):
* This memory is a special type DRAM memory with an on-chip cache memory (SRAM) that acts as a high-speed buffer for the main DRAM. 

## Difference between SRAM and DRAM
Below table lists some of the differences between SRAM and DRAM:  
![SRAM-DRAM-1](https://user-images.githubusercontent.com/89963356/135195875-9e32e5d6-e8cc-4dda-92e3-382daefb7ac8.png)

 

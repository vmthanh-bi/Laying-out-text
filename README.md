<!-- PROJECT START -->
# Laying out text
Program that reads all of the text from a provided file, prompts the user for a maximum line length, and prints the text out broken 
into optimal lines.

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#help">Help</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About the project

The objective of this program is read all of the text from a file named "input.txt", prompt the user for a maximum line length, and finally
print the text out to the console optimally broken into lines of length less than or equal to the given maximum.

Below are two examples of laid out text (describing my approach to the project):

The first example is a block of text laid out using a maximum line size of 60 characters per line and the naive line breaking algorithm that
simply tries to put as many words per line as possible. 

```
The most important observation is that this problem has a
natural recursive structure: to lay out a large block of
text, I start by deciding how many words should appear on
the first line. Once I make that decision, the problem
reduces to recursively laying out the remaining words on the
following lines. In deciding how many words to put on the
first line, I have to start by determining the maximum
number of words that will fit on that first line. Then, I
would try every possible configuration for that first line,
ranging from putting just one word on that line up to the
maximum number of words that will fit on that line. For each
configuration I try, I will need to figure out the
penalty for the first line and add that penalty to the
lowest penalty returned by the recursive call. The winning
configuration is the one that minimizes the sum of the first
line penalty and the subsequent line penalties.
```

The second example is the output the program should produce using the dynamic programming optimal line breaking algorithm.

```
The most important observation is that this problem has
a natural recursive structure: to lay out a large block
of text, I start by deciding how many words should appear
on the first line. Once I make that decision, the problem
reduces to recursively laying out the remaining words on
the following lines. In deciding how many words to put on
the first line, I have to start by determining the maximum
number of words that will fit on that first line. Then,
I would try every possible configuration for that first
line, ranging from putting just one word on that line up
to the maximum number of words that will fit on that line.
For each configuration I try, I will need to figure out
the penalty for the first line and add that penalty to the
lowest penalty returned by the recursive call. The winning
configuration is the one that minimizes the sum of the first
line penalty and the subsequent line penalties.
```

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

Things you need to use the software.
* MacOS
* Xcode

### Installation

Clone this repo.
   ```sh
   git clone https://github.com/vmthanh-bi/Prim-s-Algorithm.git
   ```

<!-- Help -->
## Help

See the [open issues](https://github.com/vmthanh-bi/Prim-s-Algorithm/issues) for a list of proposed features (and known issues).

<!-- CONTACT -->
## Contact

Tony Vu - [@vmthanh.bi](https://github.com/vmthanh-bi) - vmthanh.bi@gmail.com

Project Link: [https://github.com/vmthanh-bi/Prim-s-Algorithm](https://github.com/vmthanh-bi/Prim-s-Algorithm)

<!-- MARKDOWN LINKS & IMAGES -->


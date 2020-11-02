
# ft_ssl_md5 [(subject)](https://cdn.intra.42.fr/pdf/pdf/13242/en.subject.pdf)

## Introduction

You will recode part of the OpenSSL program, specifically the MD5 Hashing Algorithm.

## Objective

This is the first ft_ssl project on the path of Encryption and Security. You will recode some security technologies you may have already been using, from scratch.
You will want to plan out the structure of your executable before you begin, because you will build directly onto it in later security projects. It is of vital importance that your functions are modular, your code is easy to re-use and adding onto the executable doesn’t require rewriting the program.
Re-read that last sentence again. I’m serious, do it.
This project will focus specifically on cryptographic hashing algorithms to solidify your understanding of bitwise operations, integer overflow, and one-way functions. A subplot to this project is to emphasize writing clean code that can be efficiently extended.

### Install
<pre>
<code>git clone https://github.com/ChokMania/ft_ssl_md5.git</code>
<code>cd ft_ssl_md5; make</code>
</pre> 

### Usage
<pre><code>Usage: ./ft_ssl [Message Digest commands] [flags] [file]

Message Digest commands:
md5     sha224  sha256  sha384  sha512

Flags:
[-pqrlv] [-s string]
</code></pre>

### <span>test.sh</span> ft_ssl_md5
<pre><code>sh test/test.sh</code></pre>
This will show you :
<pre> ------------------------------------------
|  1.md5     2.sha224  3.sha256  4.sha384  |
|  5.sha512  6.all     0.Exit    .         |
 ------------------------------------------</pre>
 >Simply choose one of the options to launch the test.

### Exemple for ft_ssl_md5

<pre><code>./ft_ssl md5 -s Test</code></pre>
>This will convert the string "Test" in md5
<pre><code>md5 ("Test") = 0cbc6611f5540bd0809a388dc95a615b</code></pre>
> Without verbose

<pre><code>./ft_ssl md5 -v -s Test</code></pre>
<pre><code>w[ 0] = 54657374
w[ 1] = 80000000
w[ 2] = 00000000
w[ 3] = 00000000
w[ 4] = 00000000
w[ 5] = 00000000
w[ 6] = 00000000
w[ 7] = 00000000
w[ 8] = 00000000
w[ 9] = 00000000
w[10] = 00000000
w[11] = 00000000
w[12] = 00000000
w[13] = 00000000
w[14] = 20000000
w[15] = 00000000

Block [ 1 / 1 ]  str = Test

init a = 67452301 b = efcdab89 c = 98badcfe d = 10325476
   0 a = 10325476 b = ded2912e c = efcdab89 d = 98badcfe
   1 a = 98badcfe b = 0c74ddac c = ded2912e d = efcdab89
   2 a = efcdab89 b = 0e823716 c = 0c74ddac d = ded2912e
   3 a = ded2912e b = f765ae19 c = 0e823716 d = 0c74ddac
   4 a = 0c74ddac b = 26f1f70a c = f765ae19 d = 0e823716
   5 a = 0e823716 b = 2b911f30 c = 26f1f70a d = f765ae19
   6 a = f765ae19 b = 93f67a80 c = 2b911f30 d = 26f1f70a
   7 a = 26f1f70a b = 1cfd89f8 c = 93f67a80 d = 2b911f30
   8 a = 2b911f30 b = 5054bb5a c = 1cfd89f8 d = 93f67a80
   9 a = 93f67a80 b = 1e603006 c = 5054bb5a d = 1cfd89f8
  10 a = 1cfd89f8 b = 3eb779ad c = 1e603006 d = 5054bb5a
  11 a = 5054bb5a b = 41b8a872 c = 3eb779ad d = 1e603006
  12 a = 1e603006 b = ac3af8df c = 41b8a872 d = 3eb779ad
  13 a = 3eb779ad b = 10ebabca c = ac3af8df d = 41b8a872
  14 a = 41b8a872 b = dd95f8a0 c = 10ebabca d = ac3af8df
  15 a = ac3af8df b = 3a44feb6 c = dd95f8a0 d = 10ebabca
  16 a = 10ebabca b = 30082b25 c = 3a44feb6 d = dd95f8a0
  17 a = dd95f8a0 b = 0922ab2b c = 30082b25 d = 3a44feb6
  18 a = 3a44feb6 b = 48a7ae2a c = 0922ab2b d = 30082b25
  19 a = 30082b25 b = a691c747 c = 48a7ae2a d = 0922ab2b
  20 a = 0922ab2b b = 7e2a17ef c = a691c747 d = 48a7ae2a
  21 a = 48a7ae2a b = b037f3e2 c = 7e2a17ef d = a691c747
  22 a = a691c747 b = 0a5d3a43 c = b037f3e2 d = 7e2a17ef
  23 a = 7e2a17ef b = 5f7ec27e c = 0a5d3a43 d = b037f3e2
  24 a = b037f3e2 b = b0d4c995 c = 5f7ec27e d = 0a5d3a43
  25 a = 0a5d3a43 b = 7c5cf526 c = b0d4c995 d = 5f7ec27e
  26 a = 5f7ec27e b = 40b97429 c = 7c5cf526 d = b0d4c995
  27 a = b0d4c995 b = f9a88b3d c = 40b97429 d = 7c5cf526
  28 a = 7c5cf526 b = 65ef0437 c = f9a88b3d d = 40b97429
  29 a = 40b97429 b = 523fab1c c = 65ef0437 d = f9a88b3d
  30 a = f9a88b3d b = 53c7ea42 c = 523fab1c d = 65ef0437
  31 a = 65ef0437 b = 80e594ea c = 53c7ea42 d = 523fab1c
  32 a = 523fab1c b = f156c7c8 c = 80e594ea d = 53c7ea42
  33 a = 53c7ea42 b = 242eb7a9 c = f156c7c8 d = 80e594ea
  34 a = 80e594ea b = 541dceac c = 242eb7a9 d = f156c7c8
  35 a = f156c7c8 b = 459de6f1 c = 541dceac d = 242eb7a9
  36 a = 242eb7a9 b = 01e30efd c = 459de6f1 d = 541dceac
  37 a = 541dceac b = 8752a300 c = 01e30efd d = 459de6f1
  38 a = 459de6f1 b = ec6ab105 c = 8752a300 d = 01e30efd
  39 a = 01e30efd b = 19224d65 c = ec6ab105 d = 8752a300
  40 a = 8752a300 b = e2b11f9e c = 19224d65 d = ec6ab105
  41 a = ec6ab105 b = eb538791 c = e2b11f9e d = 19224d65
  42 a = 19224d65 b = a24859ab c = eb538791 d = e2b11f9e
  43 a = e2b11f9e b = a9ad0441 c = a24859ab d = eb538791
  44 a = eb538791 b = 7d79a96a c = a9ad0441 d = a24859ab
  45 a = a24859ab b = de295bb0 c = 7d79a96a d = a9ad0441
  46 a = a9ad0441 b = ab682898 c = de295bb0 d = 7d79a96a
  47 a = 7d79a96a b = 1fa371b2 c = ab682898 d = de295bb0
  48 a = de295bb0 b = cd270c10 c = 1fa371b2 d = ab682898
  49 a = ab682898 b = 714f3f9d c = cd270c10 d = 1fa371b2
  50 a = 1fa371b2 b = f1658957 c = 714f3f9d d = cd270c10
  51 a = cd270c10 b = bb196691 c = f1658957 d = 714f3f9d
  52 a = 714f3f9d b = 12cec471 c = bb196691 d = f1658957
  53 a = f1658957 b = a1412309 c = 12cec471 d = bb196691
  54 a = bb196691 b = 1fba9748 c = a1412309 d = 12cec471
  55 a = 12cec471 b = 54ee8a54 c = 1fba9748 d = a1412309
  56 a = a1412309 b = 43d1aa04 c = 54ee8a54 d = 1fba9748
  57 a = 1fba9748 b = e97cdb5e c = 43d1aa04 d = 54ee8a54
  58 a = 54ee8a54 b = 01a89112 c = e97cdb5e d = 43d1aa04
  59 a = 43d1aa04 b = 55078a27 c = 01a89112 d = e97cdb5e
  60 a = e97cdb5e b = aa21990b c = 55078a27 d = 01a89112
  61 a = 01a89112 b = 4b2f0653 c = aa21990b d = 55078a27
  62 a = 55078a27 b = f47dbd82 c = 4b2f0653 d = aa21990b
  63 a = aa21990b b = e03da96c c = f47dbd82 d = 4b2f0653

h0 = 0cbc6611 h1 = f5540bd0 h2 = 809a388d h3 = c95a615b
md5 ("Test") = 0cbc6611f5540bd0809a388dc95a615b
</code></pre>
> With verbose


## Authors
[Florian Blanchard](https://github.com/floblanc), [Antoine Pouchet](https://github.com/apouchet) et [Julien Dumay](https://github.com/ChokMania/)

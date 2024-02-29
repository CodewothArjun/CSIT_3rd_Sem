// Question : Tower of Honai

let n = 2,
  from,
  to,
  temp;

function TOH(n, from, temp, to) {
  if (n == 1) {
    console.log(`Move disk ${n} from ${from} to ${to} `);
  } else if (n > 1) {
    TOH(n - 1, from, to, temp);
    console.log(`Move disk ${n} from ${from} to ${to} `);
    TOH(n - 1, temp, from, to);
  }
}

TOH(n, "A", "B", "C");

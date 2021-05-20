 object Regex {
        @JvmStatic
        fun main(args: Array<String>) {
            val str1 = "I'm the {First string} to be found. ()?"
            val str2 = "I'm the (SECOND string) to be found. Right? (haha?._,?)"
            val pattern: Pattern = Pattern.compile("\\{([^}]+)\\}")
            matchPattern(str1, pattern)
            matchPattern(str2, pattern)
        }

        private fun matchPattern(str1: String, pattern: Pattern) {
            val m: Matcher = pattern.matcher(str1)
            while (m.find()) {
                println(m.group(1))
            }
        }
    }